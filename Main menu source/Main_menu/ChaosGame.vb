Public Class ChaosGame
    Dim pnlIndex As Integer = 0
    Dim itemSelected As Boolean = False
    Dim g As Graphics
    Dim black As Pen
    Dim green As Pen
    Dim controlIsPressed As Boolean = False

    Private Sub pnlSetPoints_Click(sender As Object, e As MouseEventArgs) Handles pnlSetPoints.Click
        'Draws a green dot where the user clicked in the panel
        DrawDot(e.X, e.Y, green)
        'Adds the point where the user clicked to the list of points
        lsvPoints.Items.Insert(pnlIndex, e.X.ToString() + ", " + e.Y.ToString())
        pnlIndex += 1
    End Sub

    Private Sub ChaosGame_closed(sender As Object, e As FormClosedEventArgs) Handles MyClass.Closed
        'Exits whole application when the form is closed
        Application.Exit()
    End Sub

    Private Sub ChaosGame_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Initalise points list
        lsvPoints.View = View.Details
        lsvPoints.Columns.Add("Points", 125, HorizontalAlignment.Left)

        'Initalise panel
        g = pnlSetPoints.CreateGraphics()
        black = New Pen(Color.Black, 1)
        green = New Pen(Color.Green, 1)
    End Sub

    Private Sub ChaosGame_KeyPressed(sender As Object, e As KeyEventArgs) Handles MyBase.KeyDown
        'Allows user to delete specific points in the point list
        If e.KeyCode = Keys.Delete Then
            If itemSelected = True Then
                removeDot(lsvPoints.SelectedIndices(0))
            End If
            'Allows user to undo the previous points added by pressing cntrl+z
        ElseIf e.KeyCode = Keys.ControlKey Then
            controlIsPressed = True
        ElseIf e.KeyCode = Keys.Z And controlIsPressed = True And pnlIndex > 0 Then

            removeDot(pnlIndex - 1)
        End If

    End Sub

    Private Sub ChaosGame_KeyReleased(sender As Object, e As KeyEventArgs) Handles MyBase.KeyUp
        'Used to check if the user wants to undo when the z key is pressed
        If e.KeyCode = Keys.ControlKey Then
            controlIsPressed = False
        End If

    End Sub

    Private Sub lsvPoints_SelectedIndexChanged(sender As Object, e As EventArgs) Handles lsvPoints.SelectedIndexChanged
        'Used to see if the user wants to delete a specific point when the user presses the delete key
        itemSelected = True
    End Sub

    Private Sub DrawDot(ByVal x As Integer, ByVal y As Integer, ByRef p As Pen)
        'Draws a dot on the screen
        g.DrawRectangle(p, x, y, 1, 1)
    End Sub

    Private Sub removeDot(ByVal i)
        'Draws a black dot over the green dot to hide the dot that is being deleted
        DrawDot(lsvPoints.Items(i).SubItems(0).Text.Split(",")(0), lsvPoints.Items(i).SubItems(0).Text.Split(" ")(1), black)

        'Removes point from point list
        lsvPoints.Items.RemoveAt(i)
        pnlIndex -= 1
        itemSelected = False
    End Sub

    Private Sub btnConfirm_click(sender As Object, e As EventArgs) Handles btnConfirm.Click
        Dim file = getFile.getFile()
        'Writes the fractal to be genorated by the main application
        file.WriteLine("chaosGame")
        'Writes the number of points to the file to be used by the main application
        file.WriteLine(pnlIndex)

        'Writes each individual points coordinates to the file
        For Each currentItem As ListViewItem In lsvPoints.Items

            'Parses the points coordinates from the point list 
            'Normalises points to fit the plane that the main application is using
            Dim x As Integer = currentItem.SubItems(0).Text.Split(",")(0) * 3.333
            Dim y As Integer = currentItem.SubItems(0).Text.Split(" ")(1)

            'Flips the y value to conform to the bitmap standard
            y = y - 300
            y = y * -1
            y += 300
            y = y * 3.333


            If x > 1999 Then
                x = 1999
            End If
            If y > 1999 Then
                y = 1999
            End If

            'Writes current point to the file
            file.WriteLine(x)
            file.WriteLine(y)

        Next
        file.Close()
        Application.Exit()
    End Sub

End Class