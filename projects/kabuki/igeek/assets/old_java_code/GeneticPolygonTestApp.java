/* The Leukocyte Wars
@file       ~/VirusPopulation.java
@date       June 2, 2014
@author     Cale Jamison McCollough
@copyright  Cale Jamison McCollough
@license    http://opensource.org/licenses/MIT
@brief      This file contains the GeneticPolygonTestPanel class.
@desc       This file contains the leukocytewars.VirusPopulation class.
*/
package leukocytewars;

import javax.swing.*;

public class GeneticPolygonTestApp extends JApplet
{   
    public GeneticPolygonTestApp ()
    {
        add (new GeneticPolygonTestPanel ());
    }
    
    public static void main (String[] args)
    {
        JFrame window = new JFrame ("GeneticPolygon Test App");
        window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

        window.setContentPane (new GeneticPolygonTestPanel ());
        
        window.pack ();
        window.setVisible (true);
    }
}
