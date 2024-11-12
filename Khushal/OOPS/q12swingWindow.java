import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class q12swingWindow extends JFrame {
    private int rectX = 100, rectY = 100, rectWidth = 200, rectHeight = 150;

    public q12swingWindow() {
        setTitle("Mouse Check in Swing Window");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                int mouseX = e.getX();
                int mouseY = e.getY();
                if (mouseX >= 0 && mouseX <= getWidth() && mouseY >= 0 && mouseY <= getHeight()) {
                    System.out.println("Mouse is inside the Swing window.");
                } else {
                    System.out.println("Mouse is outside the Swing window.");
                }
                if (mouseX >= rectX && mouseX <= rectX + rectWidth && mouseY >= rectY && mouseY <= rectY + rectHeight) {
                    System.out.println("Mouse is inside the rectangle.");
                } else {
                    System.out.println("Mouse is outside the rectangle.");
                }
            }
        });
    }
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.GREEN);
        g.fillRect(rectX, rectY, rectWidth, rectHeight); 
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new q12swingWindow().setVisible(true);
            }
        });
    }
}
