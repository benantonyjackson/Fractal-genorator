Module getFile
    'Returns StreamWriter object that is used to write the users input to the file the main program uses
    Function getFile() As IO.StreamWriter
        Dim file As System.IO.StreamWriter
        file = My.Computer.FileSystem.OpenTextFileWriter("cmd.txt", False, System.Text.Encoding.ASCII)
        Return file
    End Function
End Module
