Module main
    Sub main()
        Dim fileBrowser As New SaveFileDialog()

        While fileBrowser.FileName = ""
            fileBrowser.Title = "Save file"
            fileBrowser.Filter = "bitmap files (*.bmp)|*.bmp"
            fileBrowser.FilterIndex = 2


            Dim response = fileBrowser.ShowDialog()

            If response = DialogResult.Cancel Then
                fileBrowser.FileName = "*"
            End If


        End While
        Dim fileName As String = ""
        For i As Integer = 0 To fileBrowser.FileName.Length - 1
            If fileBrowser.FileName(i) = "\" Then
                fileName += "\\"

            Else
                fileName += fileBrowser.FileName(i)
            End If
        Next

        'fileName = fileBrowser.FileName.Replace("/", "\\")

        Dim file As System.IO.StreamWriter
        file = My.Computer.FileSystem.OpenTextFileWriter("file_name.txt", False, System.Text.Encoding.ASCII)
        file.WriteLine(fileName)
        file.Close()
    End Sub
End Module
