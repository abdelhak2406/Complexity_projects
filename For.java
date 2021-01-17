import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class For {

    public static void main(String[] args) {


        List<Double> inputs = new ArrayList<Double>(){{
            add(1E6);add(2E6);add(1E7);add(2E7);add(1E8);add(2E8);
            add(1E9);add(2E9);add(1E10);add(2E10);add(1E11);add(2E12);
            add(1E13);add(2E13);add(1E14);add(2E14);
        }};



        long finish;
        long timeElapsed;
        long durationNano;
        double i,n,s=0;

        //Scanner read = new Scanner(System.in);  /* Create a Scanner object*/
        System.out.println("give a number: ");


        //n = read.nextDouble();  /*Read user input*/
        for (int j=0; j<inputs.size(); j++) {
            long start = System.nanoTime();
            n = inputs.get(j);

            for (i=1;i<=n;i++) {
                s = s + i;
            } ;

            finish = System.nanoTime();
            durationNano = (finish - start);
            timeElapsed = TimeUnit.NANOSECONDS.toMillis(durationNano);
            //double timeElapsed = Duration.between(start,finish).toMillis();
            System.out.println("n = "+n+"\t time= " + timeElapsed+" ms");
        }
        //instant2 = clock.instant();
        // System.out.println("instant 2"+instant2);

        System.out.println("somme = "+s);

    }
}
