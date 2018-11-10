Public Class JuliaSet
    Private Sub JuliaSet_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub JuliaSet_Closed(sender As Object, e As FormClosedEventArgs) Handles MyBase.Closed
        Application.Exit()
    End Sub

    'Allows user to set a point on the complex plane with the mouse
    Private Sub pnlPickPoint_Clicked(sender As Object, e As MouseEventArgs) Handles pnlPickPoint.Click

        'Gets the location the user clicked on the panel
        Dim temp As Point = e.Location

        'Flips the Y cooridinate
        temp -= New Point(0, 250)
        temp.Y = temp.Y * -1
        temp += New Point(0, 250)

        'Scales x to be between -2 and 1
        txtReal.Text = temp.X / 250 - 2
        'Scales y to be between 1 and -1
        txtImaginary.Text = temp.Y / 250 - 1
    End Sub

    Private Sub btnConfirm_Click(sender As Object, e As EventArgs) Handles btnConfirm.Click

        If IsNumeric(txtReal.Text) = False Or IsNumeric(txtImaginary.Text) = False Then
            MsgBox("Enter numeric values into the textboxes only. Imaginary number box should not contain an i on the. For example ""1i"" should be ""1""")
        ElseIf txtReal.Text > 4 Or txtReal.Text < -4 Then
            MsgBox("Input must be between 4 and -4")
        ElseIf txtImaginary.Text > 4 Or txtImaginary.Text < -4 Then
            MsgBox("Input must be between 4 and -4")
        Else
            'Writes command and complex number to the file
            Dim file = getFile.getFile()

            file.WriteLine("juliaSet")
            file.WriteLine(txtReal.Text)
            file.WriteLine(txtImaginary.Text)
            file.Close()


            Application.Exit()

        End If

    End Sub

    'Sets the preset the user selected to the current output
    Private Sub cmdPresets_SelectedIndexChanged(sender As Object, e As EventArgs) Handles cmdPresets.SelectedIndexChanged
        'Parses text in the selected combo box item to fit the format expected
        Dim complex(2) As String
        Dim i As Integer = 1
        Dim i2 As Integer = 0
        Dim str As String = cmdPresets.Text
        While i < str.Length - 1
            If str(i) = "-" Then
                i2 += 1
            ElseIf str(i) = "+" Then
                i2 += 1
                i += 1
            End If
            If str(i) <> " " Then
                complex(i2) += str(i)
            End If

            i += 1
        End While

        txtReal.Text = cmdPresets.Text(0) + complex(0)
        txtImaginary.Text = complex(1)


    End Sub
End Class