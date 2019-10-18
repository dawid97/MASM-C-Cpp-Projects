/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.lab.gcdandlcm.ui.controller;

import javax.swing.JOptionPane;
import pl.polsl.lab.gcdandlcm.exceptions.ExecutionErrorException;
import pl.polsl.lab.gcdandlcm.ui.model.GreatestCommonDivisor;
import pl.polsl.lab.gcdandlcm.ui.model.LeastCommonMultiple;
import pl.polsl.lab.gcdandlcm.ui.view.MainFrame;

/**
 * CalculateButtonController class uses for button control.
 * 
 * @author Dawid Ulfik
 * @version 1.0
 */
public class CalculateButtonController {
    
    /**
     * Reference to GreatestCommonDivisor class.
     */
    private GreatestCommonDivisor greatestCommonDivisor;
    
    /**
     * Reference to LeastCommonMultiple class.
     */
    private LeastCommonMultiple leastCommonMultiple;
    
    /**
     * Reference to MainFrame class.
     */
    private MainFrame mainFrame;

    /**
     * This is a constructor to initialize CalculateButtonController object.
     * @param mainFrame main frame.
     */
    public CalculateButtonController(MainFrame mainFrame) {
        this.mainFrame = mainFrame;
    }
    

    /**
     * method calculates greatest common divisor and least common multiple.
     */
    public void calculateGcdAndLcm(){
        
        int a=0;
        int b=0;
        
        try{
            
        a = Integer.parseInt(mainFrame.getFirstNumberTextField().getText());
        b = Integer.parseInt(mainFrame.getSecondNumberTextField().getText());
        
        }catch(NumberFormatException numberFormatException){
            JOptionPane.showMessageDialog(null,"1. The field of first or second number can not be empty.\n"
                                            +" 2. The field of first or second number can not be words.\n"
                                             + "3. The field of first or second number can not contain too big values." );
            System.exit(0);
        }
         
        
        int gcdResult=0;
        int lcmResult=0;
        
        try{
           
        greatestCommonDivisor = new GreatestCommonDivisor(a,b);
        gcdResult=greatestCommonDivisor.calculate();
          
        leastCommonMultiple = new LeastCommonMultiple(a,b);
        lcmResult=leastCommonMultiple.calculate();
        
        }catch(ArithmeticException arithmeticException){
            JOptionPane.showMessageDialog(null,"Can not divide by zero!.");
            System.exit(0);
        }catch(ExecutionErrorException executionErrorException){
            JOptionPane.showMessageDialog(null,executionErrorException.getMessage());
            System.exit(0);
        }
        
        mainFrame.getGcdResultTextField().setText(Integer.toString(gcdResult));
        mainFrame.getLcmResultTextField().setText(Integer.toString(lcmResult));
    }
}
