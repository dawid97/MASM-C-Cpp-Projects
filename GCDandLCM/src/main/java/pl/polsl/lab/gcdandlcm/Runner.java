/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.lab.gcdandlcm;

import javax.swing.JFrame;
import pl.polsl.lab.gcdandlcm.ui.view.MainFrame;

/**
 * Runner class uses for launch main window.
 * 
 * @author Dawid
 * @version 1.0
 */
public class Runner {
    
    /**
     * To launch the main application window.
     * @param args no program arguments.
     */
    public static void main(String[] args){
        
        JFrame mainWindow=new JFrame();
        mainWindow.setBounds(0,0,600,400);
        mainWindow.setLayout(null);
        mainWindow.setContentPane(new MainFrame());
        mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainWindow.setVisible(true);
    }
}
