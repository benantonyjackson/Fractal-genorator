Public Class SierpinskiTriangle
    Private Sub SierpinskiTriangle_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub SierpinskiTriangle_Closed(sender As Object, e As FormClosedEventArgs) Handles MyBase.Closed

        Application.Exit()
    End Sub

    Private Sub btnConfirm_Click(sender As Object, e As EventArgs) Handles btnConfirm.Click
        Dim file = getFile.getFile()
        file.WriteLine("SierpinskiTriangle")
        file.WriteLine(nudWidth.Value)
        file.WriteLine(nudHeight.Value)
        file.Close()
        Application.Exit()
    End Sub

    Private Sub nudWidth_ValueChanged(sender As Object, e As EventArgs) Handles nudWidth.ValueChanged
        If cxbSymmetrical.Checked Then
            nudHeight.Value = nudWidth.Value
        End If
    End Sub

    Private Sub nudHeight_ValueChanged(sender As Object, e As EventArgs) Handles nudHeight.ValueChanged
        If cxbSymmetrical.Checked Then
            nudWidth.Value = nudHeight.Value
        End If
    End Sub
End Class