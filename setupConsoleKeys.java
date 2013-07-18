 public class SetupConsoleKeys extends Thread
        {
                public void run()
                {
                        SerialPort serialPort;
                        if (images)
                        {
                                serialPort = new SerialPort("COM5");
                        }
                        else
                        {
                                serialPort = new SerialPort("/dev/ttyACM1");
                        }
                        try {
                                serialPort.openPort();
                                serialPort.setParams(57600, 8, 1, 0);
                        } catch (SerialPortException e) {
                                e.printStackTrace();
                        }
                        while (true)
                        {
                                try {
                                        byte[] buffer = serialPort.readBytes(1);
 
                                        char theKey = (char)buffer[0];
                                        if (shifting)
                                                theKey = Character.toUpperCase(theKey);
                                        else
                                                theKey = Character.toLowerCase(theKey);
                                        //System.out.println(theKey);
                                        executeActionOf(theKey);
 
                                        try {Thread.sleep(50);} catch (InterruptedException e) {e.printStackTrace();}
                                }
                                catch (SerialPortException ex) {
                                        System.out.println(ex);
                                        break;
                                }
                        }
                        try {
                                serialPort.closePort();
                        } catch (SerialPortException e) {
                                e.printStackTrace();
                        }
                }
        }
