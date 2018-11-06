Module getFile
    Function getFile() As IO.StreamWriter
        Dim file As System.IO.StreamWriter
        file = My.Computer.FileSystem.OpenTextFileWriter("cmd.txt", False, System.Text.Encoding.ASCII)
        Return file
    End Function
End Module
