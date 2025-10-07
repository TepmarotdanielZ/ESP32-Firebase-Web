## I. ESP32 WITH FIREBASE-CREATING A WEB APP

This guide will teach you how to create a simple Firebase Web App to control and monitor your ESP32 board. The Web App you’ll create can be accessed worldwide to control and monitor your ESP32 from anywhere in the world. This Web App makes the bridge between the Firebase Realtime Database and the ESP32.

![1](images/62.png)

## II. INSTALLING REQUIRED SOFTWARE

**1. INSTALLING Node.js**

* **`1`**: Go to [nodejs.org](https://nodejs.org/en) and download the LTS version.

![1](images/63.png)

* **`2`**: Run the executable file and follow the installation process.
* **`3`**: Enable automatically install all the necessary tools.

![1](images/64.png)

* **`4`**: When it’s done, click Finish.

![1](images/64.png)

* **`5`**:  Terminal window will open to install the Additional Tools for Node.js. When it’s done, click any key to continue. When it’s finished, you can close the Terminal Window.

![1](images/65.png)

**2. VISUAL STUDIO CODE**

* **`1`**:**`Download for Windows`** button — click here to start downloading Visual Studio Code for your Windows system.

![1](images/1.png)

* **`2`**: The steps to continue the installation — first, select **`I accept the agreement`** 
* **`3`**: Then click **`Next >`**  to proceed with installing Visual Studio Code.

![1](images/2.png)

* **`4`**: The step to select additional tasks — check options like **`Create a desktop icon`** and **`Add to PATH`**
* **`5`**: then click **`Next >`** to continue the Visual Studio Code installation.

![1](images/3.png)

* **`6`**: Click the **`Install`** button to begin installing Visual Studio Code on your computer.”

![1](images/4.png)

**3. CREATING A PROJECT FOLDER**

* **`7`**: Select the **`FIREBASE WEB APP`** folder to open your Firebase project directory.

![1](images/5.png)

* **`8`**: Click the Visual Studio Code icon on the taskbar to open VS Code

![1](images/6.png)

* **`9`**: Click Open Folder

![1](images/7.png)

* **`10`**: Seleced DATA (E)
* **`11`**: Selected ESP32_FIREBASE Web App
* **`12`**: Click Open

![1](images/8.png)

**4. INSTALLING FIREBASE TOOLS (VS CODE)**

* **`13`**: The project folder named **`FIREBASE WEB APP`** opened in VS Code.
* **`14`**: The **`New Terminal`** option to open a terminal for running commands. Shortcut: **`Ctrl + Shift + ~`**

![1](images/9.png)

* **`15`**: The terminal is open in the **`FIREBASE WEB APP`** project folder, ready for commands.

![1](images/10.png)

* **`16`**: Run the following command to install firebase tools globally:

```cp
npm -g install firebase-tools
```

![1](images/11.png)

* **`17`**: The terminal output shows the command **`npm -g install firebase-tools`** successfully executed, indicating that Firebase Tools have been installed (you can ignore any warnings about deprecated libraries).

![1](images/12.png)

* **`18`**: Test if Firebase was successfully installed with the following command:

```cpp
firebase --version
```

* It should return the Firebase version currently installed.

![1](images/13.png)


## III. SETTING UP A FIREBASE WEB APP PROJECT (VS CODE)
Before creating the Firebase Web App, you need to set up a Firebase Project on VS Code. These are the steps:

**1. FIREBASE LOGIN**

* **`19`**: The firebase login command showing that the user is already logged in to Firebase.

```cpp
firebase login
```

![1](images/14.png)

* **`20`**: The command **`firebase login`**, which is used to sign in to your Firebase account through the CLI.
* **`21`**: The response **`No`**, meaning the user chose not to allow Firebase to collect CLI usage and error reporting information.

![1](images/15.png)

* **`22`**: After this, it will pop up a new window on your browser to login into your firebase account.
  
![1](images/16.png)

* **`23`**: Allow Firebase CLI to access your google account.

![1](images/17.png)

* **`24`**: After this, Firebase CLI login should be successful. You can close the browser window.

![1](images/18.png)

**2. INITIALIZING WEB APP FIREBASE PROJECT**

* **`25`**: After successfully logging in, run the following command to start a Firebase project directory in the current folder.

```cpp
firebase init
```

* **`26`**: You’ll be asked if you want to initialize a Firebase project in the current directory. Enter **`Y`** and hit **`Enter`**.

![1](images/19.png)

![1](images/20.png)

* Then, use they up and down arrows and the Space key to select the options. Select the following options:

* **`28`**: RealTime Database: Configure security rules file for Realtime Database and (optionally) provision default instance.

![1](images/21.png)

* **`29`**: Hosting: Configure files for Firebase Hosting and (optionally) set up GitHub Action deploys.
  
* The selected options will show up with a green asterisk. Then, hit Enter.
  
![1](images/22.png)


* **`30`**: the image shows a section of the terminal where Firebase CLI is prompting you to select features for your project setup. Specifically, it includes:
  * A confirmation: "Are you ready to proceed? Yes"
  * A question: "Which Firebase features do you want to set up for this directory?"
  * Selected features:
    * Hosting (for Firebase Hosting setup)
    * Realtime Database (including security rules configuration and optional instance provisioning)
  * In short, this section confirms that you're initializing a Firebase project with Hosting and Realtime Database features selected.

![1](images/23.png)

* **`31`**: Select the option **`Use an existing project`** —it should be highlighted in blue—then, hit **`Enter`**.

![1](images/24.png)

* **`32`**: After that, select the Firebase project for this directory — it should be the one you previously created. In my case, it is called **`steamxlab-bdb5c (STRAMxLAB)`**. Then hit Enter to confirm your selection. (If you have multiple Firebase projects, make sure to choose the correct one associated with your ESP32 or web dashboard setup.)

![1](images/25.png)

* **`33`**: Selected project: **`steamxlab-bdb5c (STRAMxLAB)`**

![1](images/26.png)

* **`34`**: "What do you want to use as your public directory? **`public`**"
  * Meaning:
    * You've chosen (or accepted the default) folder named public to serve your web app’s static files (HTML, CSS, JS) when deploying with Firebase Hosting.
      
![1](images/27.png)

* **`35`**:  Configure as a single-page app (rewrite urls to /index.html)? **`No`**

![1](images/28.png)

* **`36`**:  Set up automatic builds and deploys with GitHub? **`No`**

![1](images/29.png)

![1](images/30.png)

* **`38`**: This line shows the log entry “Writing configuration info to **`firebase.json`**” indicating that the Firebase setup is writing its configuration file as part of initialization.
  
* **`39`**: This line indicates the completion of the Firebase initialization, i.e., “Firebase initialization complete!” confirming that the Firebase project is now ready to use

![1](images/31.png)

* **`40`**: Highlights the left Explorer/Project tree showing the opened files and folders. It indicates the current project structure (firebase web app) with folders like public, .firebase, .gitignore, and firebase.json

![1](images/32.png)

* **`42`**: To check if everything went as expected, run the following command on the VS Code Terminal window.

```cpp
firebase deploy
```

![1](images/33.png)

* **`43`**: Marks the final line in the terminal: “Deploy complete!” (or a closely related deploy finished message).
* This indicates that the deployment process finished successfully and the project is now live.

![1](images/34.png)

* **`44`**: After deploying, you should get your Hosting URL. Go to that URL. You should get access to a similar web page.

![1](images/35.png)

This web page is built using the files placed in the public folder of your Firebase project.

You can access that web page from anywhere in the world. Now, the idea is to change the files in the public folder to show your own web page instead of that one.




