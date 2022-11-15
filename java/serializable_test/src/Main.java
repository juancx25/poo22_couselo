import java.io.*;

public class Main {
    public static void main(String[] args) {
        pepe joseph = new pepe();
        pepe pepito = new pepe();
        joseph.chiquilin.entero_chiquito = 6;
        joseph.chiquilin.char_chiquito = 'T';
        joseph.str = "Esto es una prueba a ver como se guarda pepe";
        joseph.entero = 7;
        joseph.caracter = '°';
        joseph.bool1 = true;
        joseph.bool2 = false;
        joseph.bool3 = true;
        joseph.bool4 = true;
        try {
            OutputStream out = new FileOutputStream("salida.bin");
            ObjectOutputStream oos = new ObjectOutputStream(out);
            oos.writeObject(joseph);
            oos.close();

        }catch (IOException ex){
            ex.printStackTrace();
        }

        try{
            FileInputStream in = new FileInputStream("salida.bin");
            ObjectInputStream ois = new ObjectInputStream(in);
            pepito = (pepe) ois.readObject();
            System.out.println("str = "+pepito.str);
            System.out.println("entero = "+pepito.entero);
            System.out.println("caracter = "+pepito.caracter);
            System.out.println("bool1 = "+pepito.bool1);
            System.out.println("bool2 = "+pepito.bool2);
            System.out.println("bool3 = "+pepito.bool3);
            System.out.println("bool4 = "+pepito.bool4);
            ois.close();
        }catch (IOException ex){
            ex.printStackTrace();
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}