Module main
    Sub main()
        Dim fileBrowser As New SaveFileDialog()

        While fileBrowser.FileName = ""
            fileBrowser.Title = "Save file"
            fileBrowser.Filter = "bitmap files (*.bmp)|*.bmp"
            fileBrowser.FilterIndex = 2


            Dim response = fileBrowser.ShowDialog()

            If response = DialogResult.Cancel Then
                'Tells the main program that the user clicked cancel
                fileBrowser.FileName = "*"
            End If
        End While

        Dim fileName As String = ""
        'Replaces every backslash with a double backslash so c++ can read and use the file location
        For i As Integer = 0 To fileBrowser.FileName.Length - 1
            If fileBrowser.FileName(i) = "\" Then
                fileName += "\\"
            Else
                fileName += fileBrowser.FileName(i)
            End If
        Next

        'Writes the file location selected to the file for the main program
        Dim file As System.IO.StreamWriter
        file = My.Computer.FileSystem.OpenTextFileWriter("file_name.txt", False, System.Text.Encoding.ASCII)
        file.WriteLine(fileName)
        file.Close()
    End Sub
End Module
