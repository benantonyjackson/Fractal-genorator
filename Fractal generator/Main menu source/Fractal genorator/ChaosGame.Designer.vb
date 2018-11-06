<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class ChaosGame
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.pnlSetPoints = New System.Windows.Forms.Panel()
        Me.btnConfirm = New System.Windows.Forms.Button()
        Me.lsvPoints = New System.Windows.Forms.ListView()
        Me.SuspendLayout()
        '
        'pnlSetPoints
        '
        Me.pnlSetPoints.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.pnlSetPoints.Location = New System.Drawing.Point(307, 12)
        Me.pnlSetPoints.Name = "pnlSetPoints"
        Me.pnlSetPoints.Size = New System.Drawing.Size(600, 600)
        Me.pnlSetPoints.TabIndex = 0
        '
        'btnConfirm
        '
        Me.btnConfirm.Location = New System.Drawing.Point(12, 566)
        Me.btnConfirm.Name = "btnConfirm"
        Me.btnConfirm.Size = New System.Drawing.Size(100, 43)
        Me.btnConfirm.TabIndex = 1
        Me.btnConfirm.Text = "Confirm"
        Me.btnConfirm.UseVisualStyleBackColor = True
        '
        'lsvPoints
        '
        Me.lsvPoints.Location = New System.Drawing.Point(21, 49)
        Me.lsvPoints.Name = "lsvPoints"
        Me.lsvPoints.Size = New System.Drawing.Size(126, 195)
        Me.lsvPoints.TabIndex = 2
        Me.lsvPoints.UseCompatibleStateImageBehavior = False
        '
        'ChaosGame
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(921, 621)
        Me.Controls.Add(Me.lsvPoints)
        Me.Controls.Add(Me.btnConfirm)
        Me.Controls.Add(Me.pnlSetPoints)
        Me.KeyPreview = True
        Me.Name = "ChaosGame"
        Me.Text = "ChaosGame"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents pnlSetPoints As Panel
    Friend WithEvents btnConfirm As Button
    Friend WithEvents lsvPoints As ListView
End Class
