# SlopeIntercept-project
a program made in C++ design to convert either two-point form or point-slope form into slopeintercept form, calculate the line’s length, angle, and degrees and graph the line with class objects. This program was meant to be my final exam of my Programming methodology class (COP 2001) at Florida Gulf Coast University (FGCU).

## Demonstration

Here is an animated gif of the program running, show casing some of its main features. <br />
![Demonstration GIF](resources/Demonstration.gif)  <br />
Here is a link to a longer video showing off some of the changes made taking into consideration human user factor:  <br />
https://youtu.be/4DHntUlHWFk

## Diagrams

Class Diagram: <br />
![Class Diagram](resources/ClassesDiagram.png) <br />
Database Diagram: <br />
![Database Diagram](resources/DatabaseDiagram.png) <br />

## Getting Started

In order to get the program running in your computer in IntelliJ you need to follow the next steps:
1. Copy the URL for this repository.
2. Open IntelliJ.
3. Close any projects that you might have open at the time.
4. Click on "Get from Version Control".
5. Make sure that on the left side you have selected "Repository URL", and in the choice box for "Version Control" on top is selected "Git".
6. Paste the URL of the repository where says "URL" and click "Clone".
7. After it is cloned, go to OOP>src>main>java and right click the "Main" class and click on "Run 'Main.main()'".
8. Finally, if the program does not run, go to "Run" on the menu bar on top. Then, click on "Edit Configurations" and paste this into the "VM Options" text box:

                      --module-path C:\Users\ronal\javafx-sdk-11.0.2\lib --add-modules javafx.controls,javafx.fxml 
                      
 (but include the directory where is located your javafx.lib. in your computer.)
 9. Then right click Main and run it again, and it should run smoothly. <br />
## Built With
* JavaFX project using Java 11 and Gradle.
* IDE: IntelliJ IDEA Ultimate version 2020.2 
* H2 Database Engine version 1.4.200 (2019-10-14)
* SceneBuilder for Java 11 version 11.0.0  

## Contributing
Because of the timespan there were many things that I have to leave out. Thus, the program still has much room for improvement such as: we can make that the database reads the username and password from a text file or maybe we can make it a login window where we need to enter the correct username and password to access to the database. Also, the Employee tab functions by itself, but it really does not contribute to the program as whole. It can be added that once the employee signs in, then in the production log tab is registered which employee added or produced that specific product. I am just sharing some ideas that I might try to work on for this program after. <br />

## Author

* Ronald Quiroz.

## License

[License](LICENSE) <br />


## Acknowledgments

* The course website, put together by my professor, was of massive help from the instructions all the way to the extra resources.
* I appreciate the help of my professor Scott Vanselow for help me out when I was stuck.

## History

This is the completed version after a semester of putting together small parts of the program at a time.

## Key Programming Concepts Utilized
* Object Oriented Programming: programming base on objects created with a particular behavior. <br />
* Enum: A group of constants variables. <br />
* Interfaces: A contract class with abstract methods (without body). Another class must implement this interface for it to access the methods and give them a body. <br />
* Abstract Class: A class that cannot be instantiated, but it can be referenced. So, we can talk about this class, but we cannot create objects of this class. <br />
* Overring methods: A method in a subclass with the same name, parameters and return type as a method in its super class. <br />
* Overloading methods: Two methods with the same name, but different parameters.
