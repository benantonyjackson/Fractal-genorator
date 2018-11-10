Public Class SierpinskiTriangle
    'Used to check which box was last edited
    '0 means neither have been edited
    '1 means width
    '2 means height
    Dim lastChanged As Integer = 0

    Private Sub SierpinskiTriangle_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub SierpinskiTriangle_Closed(sender As Object, e As FormClosedEventArgs) Handles MyBase.Closed
        'Exits whole application when the form is closed
        Application.Exit()
    End Sub

    Private Sub btnConfirm_Click(sender As Object, e As EventArgs) Handles btnConfirm.Click
        'Writes the user input to the file
        Dim file = getFile.getFile()
        file.WriteLine("SierpinskiTriangle")
        file.WriteLine(nudWidth.Value)
        file.WriteLine(nudHeight.Value)
        file.Close()
        Application.Exit()
    End Sub

    Private Sub nudWidth_ValueChanged(sender As Object, e As EventArgs) Handles nudWidth.ValueChanged
        'States that the width was the last thing changed 
        lastChanged = 1
        'Sets the height to the width if the user has the symetrical check box checked 
        If cxbSymmetrical.Checked Then
            nudHeight.Value = nudWidth.Value
        End If
    End Sub

    Private Sub nudHeight_ValueChanged(sender As Object, e As EventArgs) Handles nudHeight.ValueChanged
        'Asserts that the height was the last thing changed 
        lastChanged = 2
        'Sets the width to the height if the user has the symetrical check box checked 
        If cxbSymmetrical.Checked Then
            nudWidth.Value = nudHeight.Value
        End If
    End Sub

    Private Sub cxbSymmetrical_CheckedChanged(sender As Object, e As EventArgs) Handles cxbSymmetrical.CheckedChanged
        If cxbSymmetrical.Checked = True Then
            If lastChanged = 1 Then
                'Sets the height to the width if the height was the last thing changed
                nudHeight.Value = nudWidth.Value
            ElseIf lastChanged = 2 Then
                'Sets the width to the height if the height was the last thing changed
                nudWidth.Value = nudHeight.Value
            End If
        End If
    End Sub
End Class