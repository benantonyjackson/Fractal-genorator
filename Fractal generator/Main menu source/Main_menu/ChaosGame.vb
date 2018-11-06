Public Class ChaosGame
    Dim pnlIndex As Integer = 0
    Dim itemSelected As Boolean = False
    Dim g As Graphics
    Dim black As Pen
    Dim green As Pen
    Dim controlIsPressed As Boolean = False

    Private Sub pnlSetPoints_Click(sender As Object, e As MouseEventArgs) Handles pnlSetPoints.Click
        DrawDot(e.X, e.Y, green)
        lsvPoints.Items.Insert(pnlIndex, e.X.ToString() + ", " + e.Y.ToString())
        pnlIndex += 1
    End Sub

    Private Sub ChaosGame_closed(sender As Object, e As FormClosedEventArgs) Handles MyClass.Closed


        Application.Exit()
    End Sub

    Private Sub ChaosGame_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        lsvPoints.View = View.Details
        lsvPoints.Columns.Add("Points", 125, HorizontalAlignment.Left)
        g = pnlSetPoints.CreateGraphics()

        black = New Pen(Color.Black, 1)
        green = New Pen(Color.Green, 1)
    End Sub

    Private Sub ChaosGame_KeyPressed(sender As Object, e As KeyEventArgs) Handles MyBase.KeyDown
        If e.KeyCode = Keys.Delete Then
            If itemSelected = True Then
                removeDot(lsvPoints.SelectedIndices(0))
            End If
        ElseIf e.KeyCode = Keys.ControlKey Then

            controlIsPressed = True
            'MsgBox(controlIsPressed)
        ElseIf e.KeyCode = Keys.Z And controlIsPressed = True And pnlIndex > 0 Then
            ' MsgBox(controlIsPressed)
            removeDot(pnlIndex - 1)
        End If

    End Sub

    Private Sub ChaosGame_KeyReleased(sender As Object, e As KeyEventArgs) Handles MyBase.KeyUp
        If e.KeyCode = Keys.ControlKey Then
            controlIsPressed = False
            '  MsgBox(controlIsPressed)
        End If

    End Sub

    Private Sub lsvPoints_SelectedIndexChanged(sender As Object, e As EventArgs) Handles lsvPoints.SelectedIndexChanged
        itemSelected = True
    End Sub

    Private Sub DrawDot(ByVal x As Integer, ByVal y As Integer, ByRef p As Pen)
        g.DrawRectangle(p, x, y, 1, 1)
    End Sub

    Private Sub removeDot(ByVal i)
        DrawDot(lsvPoints.Items(i).SubItems(0).Text.Split(",")(0), lsvPoints.Items(i).SubItems(0).Text.Split(" ")(1), black)

        lsvPoints.Items.RemoveAt(i)
        pnlIndex -= 1
        itemSelected = False
    End Sub

    Private Sub btnConfirm_click(sender As Object, e As EventArgs) Handles btnConfirm.Click
        Dim file = getFile.getFile()
        file.WriteLine("chaosGame")
        file.WriteLine(pnlIndex)
        For Each currentItem As ListViewItem In lsvPoints.Items

            Dim x As Integer = currentItem.SubItems(0).Text.Split(",")(0) * 3.333
            Dim y As Integer = currentItem.SubItems(0).Text.Split(" ")(1)
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

            file.WriteLine(x)
            file.WriteLine(y)

        Next
        file.Close()
        Application.Exit()
    End Sub

End Class