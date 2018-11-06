<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.MandelbrotSet = New System.Windows.Forms.Button()
        Me.JuliaSet = New System.Windows.Forms.Button()
        Me.SierpinskiTriangle = New System.Windows.Forms.Button()
        Me.ChaosGame = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'MandelbrotSet
        '
        Me.MandelbrotSet.Location = New System.Drawing.Point(12, 12)
        Me.MandelbrotSet.Name = "MandelbrotSet"
        Me.MandelbrotSet.Size = New System.Drawing.Size(146, 65)
        Me.MandelbrotSet.TabIndex = 0
        Me.MandelbrotSet.Text = "Mandelbrot Set"
        Me.MandelbrotSet.UseVisualStyleBackColor = True
        '
        'JuliaSet
        '
        Me.JuliaSet.Location = New System.Drawing.Point(182, 12)
        Me.JuliaSet.Name = "JuliaSet"
        Me.JuliaSet.Size = New System.Drawing.Size(146, 65)
        Me.JuliaSet.TabIndex = 1
        Me.JuliaSet.Text = "Julia set"
        Me.JuliaSet.UseVisualStyleBackColor = True
        '
        'SierpinskiTriangle
        '
        Me.SierpinskiTriangle.Location = New System.Drawing.Point(12, 95)
        Me.SierpinskiTriangle.Name = "SierpinskiTriangle"
        Me.SierpinskiTriangle.Size = New System.Drawing.Size(146, 65)
        Me.SierpinskiTriangle.TabIndex = 2
        Me.SierpinskiTriangle.Text = "Sierpinski triangle"
        Me.SierpinskiTriangle.UseVisualStyleBackColor = True
        '
        'ChaosGame
        '
        Me.ChaosGame.Location = New System.Drawing.Point(182, 95)
        Me.ChaosGame.Name = "ChaosGame"
        Me.ChaosGame.Size = New System.Drawing.Size(146, 65)
        Me.ChaosGame.TabIndex = 3
        Me.ChaosGame.Text = "Chaos game"
        Me.ChaosGame.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(346, 179)
        Me.Controls.Add(Me.ChaosGame)
        Me.Controls.Add(Me.SierpinskiTriangle)
        Me.Controls.Add(Me.JuliaSet)
        Me.Controls.Add(Me.MandelbrotSet)
        Me.Name = "Form1"
        Me.Text = "Fractal generator"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents MandelbrotSet As Button
    Friend WithEvents JuliaSet As Button
    Friend WithEvents SierpinskiTriangle As Button
    Friend WithEvents ChaosGame As Button
End Class
