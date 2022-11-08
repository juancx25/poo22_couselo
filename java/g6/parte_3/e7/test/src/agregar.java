import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class agregar extends empresa{
    private JButton agregarButton;
    private JTextField nombreField;
    private JTextField apellidoField;
    public JPanel agregarPanel;

    public agregar() {
        agregarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                if ((nombreField.getText() != "") && (apellidoField.getText() != "")){
                    persona aux = new persona(nombreField.getText(),apellidoField.getText());
                    agregar.super.empleados.add(aux);
                }
            }
        });
    }
}
