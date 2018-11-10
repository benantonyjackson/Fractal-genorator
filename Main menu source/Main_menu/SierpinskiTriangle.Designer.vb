<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SierpinskiTriangle
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
        Me.nudWidth = New System.Windows.Forms.NumericUpDown()
        Me.nudHeight = New System.Windows.Forms.NumericUpDown()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.cxbSymmetrical = New System.Windows.Forms.CheckBox()
        Me.btnConfirm = New System.Windows.Forms.Button()
        CType(Me.nudWidth, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.nudHeight, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'nudWidth
        '
        Me.nudWidth.Location = New System.Drawing.Point(146, 50)
        Me.nudWidth.Maximum = New Decimal(New Integer() {20000, 0, 0, 0})
        Me.nudWidth.Minimum = New Decimal(New Integer() {100, 0, 0, 0})
        Me.nudWidth.Name = "nudWidth"
        Me.nudWidth.Size = New System.Drawing.Size(162, 20)
        Me.nudWidth.TabIndex = 0
        Me.nudWidth.Value = New Decimal(New Integer() {100, 0, 0, 0})
        '
        'nudHeight
        '
        Me.nudHeight.Location = New System.Drawing.Point(146, 76)
        Me.nudHeight.Maximum = New Decimal(New Integer() {20000, 0, 0, 0})
        Me.nudHeight.Minimum = New Decimal(New Integer() {100, 0, 0, 0})
        Me.nudHeight.Name = "nudHeight"
        Me.nudHeight.Size = New System.Drawing.Size(162, 20)
        Me.nudHeight.TabIndex = 1
        Me.nudHeight.Value = New Decimal(New Integer() {100, 0, 0, 0})
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(67, 52)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(70, 13)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "Width (pixels)"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(67, 78)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(73, 13)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Height (pixels)"
        '
        'cxbSymmetrical
        '
        Me.cxbSymmetrical.AutoSize = True
        Me.cxbSymmetrical.Location = New System.Drawing.Point(226, 27)
        Me.cxbSymmetrical.Name = "cxbSymmetrical"
        Me.cxbSymmetrical.Size = New System.Drawing.Size(82, 17)
        Me.cxbSymmetrical.TabIndex = 3
        Me.cxbSymmetrical.Text = "Symmetrical"
        Me.cxbSymmetrical.UseVisualStyleBackColor = True
        '
        'btnConfirm
        '
        Me.btnConfirm.Location = New System.Drawing.Point(12, 112)
        Me.btnConfirm.Name = "btnConfirm"
        Me.btnConfirm.Size = New System.Drawing.Size(75, 23)
        Me.btnConfirm.TabIndex = 2
        Me.btnConfirm.Text = "Confirm"
        Me.btnConfirm.UseVisualStyleBackColor = True
        '
        'SierpinskiTriangle
        '
        Me.AcceptButton = Me.btnConfirm
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(320, 147)
        Me.Controls.Add(Me.btnConfirm)
        Me.Controls.Add(Me.cxbSymmetrical)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.nudHeight)
        Me.Controls.Add(Me.nudWidth)
        Me.Name = "SierpinskiTriangle"
        Me.Text = "SierpinskiTriangle"
        CType(Me.nudWidth, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.nudHeight, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents nudWidth As NumericUpDown
    Friend WithEvents nudHeight As NumericUpDown
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents cxbSymmetrical As CheckBox
    Friend WithEvents btnConfirm As Button
End Class
