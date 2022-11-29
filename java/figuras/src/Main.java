import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.concurrent.ThreadLocalRandom;

public class Main {
    public static void main(String[] args) {
        DecimalFormat numberFormat = new DecimalFormat("#.0000");

        ArrayList<figura> arr = new ArrayList<figura>();
        for (int i=0;i<4;i++){
            triangulo t = new triangulo(ThreadLocalRandom.current().nextDouble(1,10),ThreadLocalRandom.current().nextDouble(1,10));
            rectangulo r = new rectangulo(ThreadLocalRandom.current().nextDouble(1,10),ThreadLocalRandom.current().nextDouble(1,10));
            arr.add(t);
            arr.add(r);
        }

        Collections.sort(arr, new Comparator<figura>(){

            @Override
            public int compare(figura f1, figura f2){
                double a1 = f1.area();
                double a2 = f2.area();
                if(a1 > a2){
                    return 1;
                }
                else if(a1 < a2){
                    return -1;
                }
                else {
                    return 0;
                }
            }
        });

        for (figura f : arr){
            System.out.println("Area: "+numberFormat.format(f.area()));
        }
    }
}