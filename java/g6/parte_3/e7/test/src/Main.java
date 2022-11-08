import javax.swing.*;
import java.util.Scanner;
import java.io.IOException;

public class Main {

    public final static void clearConsole()
    {
        try
        {
            final String os = System.getProperty("os.name");
            if (os.contains("Windows")){
                Runtime.getRuntime().exec("cls");
            } else
            {
                Runtime.getRuntime().exec("clear");
            }
        }
        catch (final Exception e){
            //  Handle any exceptions.
        }
    }

    public static void main(String[] args) {
        int menu = 1;
        empresa emp = new empresa();
        try{
            emp.importar_empleados("empleados.txt");
        } catch (IOException e){
            e.printStackTrace();
        }
        JFrame M = new JFrame();
        M.setContentPane(new menu().menuPanel);
        M.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        M.pack();
        M.setVisible(true);

        /*Scanner scanner = new Scanner(System.in);
        while (menu != 5){
            clearConsole();
            System.out.println("-SISTEMA EMPLEADOS-");
            System.out.println("Agregar...........1");
            System.out.println("Imprimir todos....2");
            System.out.println("Buscar............3");
            System.out.println("Eliminar..........4");
            System.out.println("Salir.............5");
            menu = scanner.nextInt();
            switch (menu){
                case 1:
                    emp.agregar_empleado();
                    break;
                case 2:
                    emp.imprimir_empleados();
                    scanner.nextLine();
                    break;
                case 3:

                    break;
            }
        }*/
        try{
            emp.exportar_empleados("empleados.txt");
        } catch (IOException e){
            e.printStackTrace();
        }
    }

}

