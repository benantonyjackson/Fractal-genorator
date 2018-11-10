Public Class MainMenu
    Private Sub MandelbrotSet_Click(sender As Object, e As EventArgs) Handles MandelbrotSet.Click
        Dim file = getFile.getFile()
        file.WriteLine("mandelbrotSet")

        file.Close()

        Application.Exit()
    End Sub

    Private Sub JuliaSet_Click(sender As Object, e As EventArgs) Handles JuliaSet.Click
        Dim juliaSet As New JuliaSet()
        juliaSet.Show()
        Me.Hide()
    End Sub


    Private Sub ChaosGme_Click(sender As Object, e As EventArgs) Handles ChaosGame.Click
        Dim chaosGame As New ChaosGame()
        chaosGame.Show()
        Hide()
    End Sub

    Private Sub SierpinskiTriangle_Click(sender As Object, e As EventArgs) Handles SierpinskiTriangle.Click
        Dim sierpinskiTriangle As New SierpinskiTriangle()
        sierpinskiTriangle.Show()
        Hide()
    End Sub
End Class
