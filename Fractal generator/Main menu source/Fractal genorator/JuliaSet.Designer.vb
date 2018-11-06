<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class JuliaSet
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(JuliaSet))
        Me.txtReal = New System.Windows.Forms.TextBox()
        Me.txtImaginary = New System.Windows.Forms.TextBox()
        Me.lblReal = New System.Windows.Forms.Label()
        Me.lblImaginary = New System.Windows.Forms.Label()
        Me.pnlPickPoint = New System.Windows.Forms.Panel()
        Me.btnConfirm = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.cmdPresets = New System.Windows.Forms.ComboBox()
        Me.SuspendLayout()
        '
        'txtReal
        '
        Me.txtReal.Location = New System.Drawing.Point(15, 28)
        Me.txtReal.Name = "txtReal"
        Me.txtReal.Size = New System.Drawing.Size(112, 20)
        Me.txtReal.TabIndex = 0
        Me.txtReal.Text = "0"
        '
        'txtImaginary
        '
        Me.txtImaginary.Location = New System.Drawing.Point(15, 78)
        Me.txtImaginary.Name = "txtImaginary"
        Me.txtImaginary.Size = New System.Drawing.Size(112, 20)
        Me.txtImaginary.TabIndex = 1
        Me.txtImaginary.Text = "0"
        '
        'lblReal
        '
        Me.lblReal.AutoSize = True
        Me.lblReal.Location = New System.Drawing.Point(12, 12)
        Me.lblReal.Name = "lblReal"
        Me.lblReal.Size = New System.Drawing.Size(32, 13)
        Me.lblReal.TabIndex = 2
        Me.lblReal.Text = "Real:"
        '
        'lblImaginary
        '
        Me.lblImaginary.AutoSize = True
        Me.lblImaginary.Location = New System.Drawing.Point(12, 62)
        Me.lblImaginary.Name = "lblImaginary"
        Me.lblImaginary.Size = New System.Drawing.Size(55, 13)
        Me.lblImaginary.TabIndex = 2
        Me.lblImaginary.Text = "Imaginary:"
        '
        'pnlPickPoint
        '
        Me.pnlPickPoint.BackgroundImage = CType(resources.GetObject("pnlPickPoint.BackgroundImage"), System.Drawing.Image)
        Me.pnlPickPoint.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pnlPickPoint.Location = New System.Drawing.Point(271, 12)
        Me.pnlPickPoint.Name = "pnlPickPoint"
        Me.pnlPickPoint.Size = New System.Drawing.Size(750, 500)
        Me.pnlPickPoint.TabIndex = 3
        '
        'btnConfirm
        '
        Me.btnConfirm.Location = New System.Drawing.Point(12, 467)
        Me.btnConfirm.Name = "btnConfirm"
        Me.btnConfirm.Size = New System.Drawing.Size(109, 45)
        Me.btnConfirm.TabIndex = 0
        Me.btnConfirm.Text = "Confirm"
        Me.btnConfirm.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 118)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(42, 13)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "Presets"
        '
        'cmdPresets
        '
        Me.cmdPresets.FormattingEnabled = True
        Me.cmdPresets.Items.AddRange(New Object() {"0+0i", "-0.4 + 0.6i", "0.285 + 0i", "0.285 + 0.01i", "0.45 + 0.1428i", "-0.70176 - 0.3842i", "-0.835 - 0.2321i", "-0.8 + 0.156i", "-0.7269 + 0.1889i", "-1 + 0i", "-0.79 + 0.15i", "-0.162 + 1.04i", "0.3 - 0.01i", "-1.476 + 0i", "-0.12 - 0.77i", "0.28 + 0.008i"})
        Me.cmdPresets.Location = New System.Drawing.Point(15, 134)
        Me.cmdPresets.Name = "cmdPresets"
        Me.cmdPresets.Size = New System.Drawing.Size(121, 21)
        Me.cmdPresets.TabIndex = 5
        '
        'JuliaSet
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1033, 523)
        Me.Controls.Add(Me.cmdPresets)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btnConfirm)
        Me.Controls.Add(Me.pnlPickPoint)
        Me.Controls.Add(Me.lblImaginary)
        Me.Controls.Add(Me.lblReal)
        Me.Controls.Add(Me.txtImaginary)
        Me.Controls.Add(Me.txtReal)
        Me.Name = "JuliaSet"
        Me.Text = "JuliaSet"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents txtReal As TextBox
    Friend WithEvents txtImaginary As TextBox
    Friend WithEvents lblReal As Label
    Friend WithEvents lblImaginary As Label
    Friend WithEvents pnlPickPoint As Panel
    Friend WithEvents btnConfirm As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents cmdPresets As ComboBox
End Class
