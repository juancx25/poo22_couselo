import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ManejadorFiguras {
    private ArrayList<figura> figuras;

    public ManejadorFiguras(){
        figuras = new ArrayList<figura>();
    }

    public void ordenar(String file_name,String criterio) throws IOException {
        if (criterio.equals("area")){
            Collections.sort(figuras, new Comparator<figura>() {
                @Override
                public int compare(figura f1, figura f2) {
                    double a1 = f1.area();
                    double a2 = f2.area();
                    if (a1 < a2) return 1;
                    else if (a1 > a2) return -1;
                    else return 0;
                }
            });
            guardarFiguras(file_name);
        }
        if (criterio.equals("perimetro")){
            Collections.sort(figuras, new Comparator<figura>() {
                @Override
                public int compare(figura f1, figura f2) {
                    double p1 = f1.perimetro();
                    double p2 = f2.perimetro();
                    if (p1 > p2) return 1;
                    else if (p1 < p2) return -1;
                    else return 0;
                }
            });
            guardarFiguras(file_name);
        }
    }

    public void recuperarFiguras(String file_name) throws IOException {
        String line = "";
        BufferedReader br = new BufferedReader(new FileReader(file_name));
        String tipo_figura;long fore_color;long back_color;double base;double altura;
        while ((line = br.readLine()) != null){
            String[] aux = line.split(";");
            tipo_figura = aux[0];
            fore_color = Long.parseLong(aux[1]);
            back_color = Long.parseLong(aux[2]);
            base = Double.parseDouble(aux[3]);


            if (tipo_figura.equals("Rectangulo")){
                altura = Double.parseDouble(aux[4]);
                rectangulo r = new rectangulo(tipo_figura,(int)fore_color,(int)back_color,base,altura);
                figuras.add(r);
            }
            if (tipo_figura.equals("Circulo")){
                circulo c = new circulo(tipo_figura,(int)fore_color,(int)back_color,base,0);
                figuras.add(c);
            }
            if (tipo_figura.equals("Triangulo")){
                altura = Double.parseDouble(aux[4]);
                triangulo t = new triangulo(tipo_figura,(int)fore_color,(int)back_color,base,altura);
                figuras.add(t);
            }

        }
        br.close();

    }

    public void guardarFiguras(String file_name) throws IOException {
        PrintWriter out = new PrintWriter(file_name);
        for (figura f : figuras){
            out.println(f.toString());
        }
        out.close();
    }

    public void recuperarFiguras_bin(String file_name) throws IOException {
        FileInputStream fis = new FileInputStream(file_name);
        DataInputStream dis = new DataInputStream(fis);
        String tipo_figura;long fore_color;long back_color;double base;double altura;

        //while(fis.available() > 0) {
        while (true) {
            try {
                int aux = dis.readInt();
                byte[] arr = new byte[aux];
                dis.read(arr);
                tipo_figura = new String(arr);

                fore_color = dis.readInt();
                back_color = dis.readInt();

                base = dis.readDouble();
                altura = dis.readDouble();

                if (tipo_figura.equals("Rectangulo")){
                    rectangulo r = new rectangulo(tipo_figura,(int)fore_color,(int)back_color,base,altura);
                    figuras.add(r);
                }
                if (tipo_figura.equals("Circulo")){
                    circulo c = new circulo(tipo_figura,(int)fore_color,(int)back_color,base,0);
                    figuras.add(c);
                }
                if (tipo_figura.equals("Triangulo")){
                    triangulo t = new triangulo(tipo_figura,(int)fore_color,(int)back_color,base,altura);
                    figuras.add(t);
                }

            } catch (EOFException eof){
                    break;
            }
        }
        fis.close();
    }

    public void guardarFiguras_bin(String file_name) throws IOException {
        FileOutputStream fos = new FileOutputStream(file_name);
        DataOutputStream dos = new DataOutputStream(fos);
        for (figura f : figuras){
            dos.writeInt(f.tipo_figura.length());
            fos.write(f.tipo_figura.getBytes());

            dos.writeInt(f.getForeColor());
            dos.writeInt(f.getBackColor());

            dos.writeDouble(f.getBase());
            dos.writeDouble(f.getAltura());

        }
        fos.close();
    }

    public void print(){
        for (figura f : figuras){
            f.print();
        }
    }
}
