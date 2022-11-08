import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class menu {
    private JButton agregarButton;
    public JPanel menuPanel;
    private JButton mostrarButton;

    public menu() {
        agregarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                JFrame add  = new JFrame("Agregar");
                add.setContentPane(new agregar().agregarPanel);
                add.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                add.setVisible(true);

            }
        });
        mostrarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                JFrame print  = new JFrame("Imprimir");
                print.setContentPane(new imprimir().imprimirPanel);
                print.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                print.setVisible(true);
            }
        });
    }
}
