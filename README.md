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

## IV.  ESP32 GETTING STARTED WITH FIREBASE (REAL TIME DATABASE)

This guide will get you started quickly with Firebase using the ESP32 board. Firebase is Google’s mobile application development platform that includes many services to manage data from IOS, Android, or web applications. You’ll create a Firebase project with a realtime database (RTDB), and you’ll learn how to store and read values from the database with your ESP32.


In a later tutorial, you’ll learn how to create a Firebase web app that you can access from anywhere to monitor and control your ESP32 using Firebase’s real-time database:

**1. WHAT IS FIREBASE?**

![Copy of Copy of TEMPLATE](https://github.com/user-attachments/assets/bfb16ccd-1dad-4202-9852-3be6f8773dfc)

Firebase is Google’s mobile application development platform that helps you build, improve, and grow your app. It has many services used to manage data from any Android, IOS, or web application.

The following paragraph clearly explains the advantages of using Firebase:

“Firebase is a toolset to “build, improve, and grow your app”, and the tools it gives you cover a large portion of the services that developers would normally have to build themselves but don’t really want to build because they’d rather be focusing on the app experience itself. This includes things like analytics, authentication, databases, configuration, file storage, push messaging, and the list goes on. The services are hosted in the cloud and scale with little to no effort on the part of the developer.”

This paragraph was taken from  [this article](https://medium.com/firebase-developers/what-is-firebase-the-complete-story-abridged-bcc730c5f2c0), and we recommend that you read that article if you want to understand better what firebase is and what it allows you to do.

You can use the ESP32 to connect and interact with your Firebase project, and you can create applications to control the ESP32 via Firebase from anywhere in the world.

In this tutorial, we’ll create a Firebase project with a realtime database, and we’ll use the ESP32 to store and read data from the database. The ESP32 can interact with the database from anywhere in the world as long as it is connected to the internet.

This means that you can have two ESP32 boards in different networks, with one board storing data and the other board reading the most recent data, for example.

![Copy of Copy of TEMPLATE (1)](https://github.com/user-attachments/assets/70cf4caf-aaca-49ff-9ceb-141cd9990072)

In a later tutorial, we’ll create a web app using Firebase that will control the ESP32 to display sensor readings or control outputs from anywhere in the world.

![Copy of Copy of TEMPLATE (2)](https://github.com/user-attachments/assets/2cf82e1d-a831-4995-828a-8af3db27e388)

## V. PROJECT OVERVIEW

In this tutorial, you’ll learn how to create a Firebase project with a realtime database and store and read data from the database using the ESP32.

To follow this project, first, you need to set up a Firebase project and create a realtime database for that project. Then, you’ll program the ESP32 to store and read data from the database. This tutorial is divided into three sections.

   **1. Create a Firebase Project**
   
   **2. ESP32: Store data to the Firebase Realtime Database**
   
   **3. ESP32: Read data from the Firebase Realtime Database**

Let’s get started!


## VI. SET UP A FIREBASE ACCOUNT AND CREATE A NEW PROJECT
**1. CREATE A NEW PROJECT**

Follow the next instructions to create a new project on Firebase.

  **1.** Go to [Firebase](https://firebase.google.com/) and sign in using a Google Account.

  **2.** Click Get Started, and then Add project to create a new project.

![1](images/36.png)

![1](images/37.png)


  **3.** Give a name to your project, for example: **`FIREBASE WEB APP`**.

![1](images/38.png)

  **4.** Enable Google Analytics for this project as it is not needed and click Create project.

![1](images/39.png)

**`7.`** Choose or create a Google Analytics account to link with your Firebase project and start tracking your app's performance seamlessly.

![1](images/40.png)

**`8.`** Enter a name for your Google Analytics account, such as **`FIREBASE WEB APP`**' and click **`Save`** to link it with your Firebase project.

![1](images/41.png)

**`9.`**  Select your preferred Google Analytics location, such as **`Singapore`**, from the dropdown menu.

**`10.`** Check the box to accept the Google Analytics terms and conditions.

**`11.`** Click the **`Create project`** button to finalize the setup.

![1](images/42.png)

**`12.`** It will take a few seconds setting up your project. Then, click **`Continue`** when it’s ready.

![1](images/43.png)

* You’ll be redirected to your Project console page.

![image](https://github.com/user-attachments/assets/5124e440-ff97-4523-9c71-85f4891950ca)


**`13.`** Click the code icon to add Firebase SDK to your app.

![1](images/44.png)

**`14.`** Enter your app nickname, such as "**`FIREBASE WEB APP`**."

**`15.`** Check the box to also set up Firebase Hosting for your app, then select the hosting site from the dropdown menu.

**`16.`** Click the "**`Register app`**" button to complete the registration process.

![1](images/45.png)

**`17.`** Run the command npm **`install firebase`** in your terminal to install the Firebase SDK.

**`18.`** Copy the **`firebaseConfig`** object, which includes your project's configuration details like **`apiKey`**, **`authDomain`**, **`projectId`**, etc.
Note: In your case, the authDomain matches the one shown in the Terminal window after setting up your Firebase project.

**`19.`** Click the "**`Next`**" button to proceed to the next step.

![1](images/46.png)

**`20.`** Run the command **`npm install -g firebase-tools`** in your terminal to install the Firebase CLI tools.

**`21.`** Click the "**`Next`**" button to proceed to the next step.

![1](images/47.png)

**`22.`** Type the command **`$ firebase login`** in the terminal to log into your Firebase accoun

**`23.`** Once logged in, type **`$ firebase init`** to initialize your Firebase project.

**`24.`** When ready to **`deploy`**, type **`$ firebase deploy`** to upload your app to Firebase hosting.

**`25.`** Click the "Continue to console" button to proceed to your Firebase project dashboard.

![1](images/48.png)

## VII. SET AUTHENTICATION METHODS

You need to set authentication methods for your app.

“Most apps need to know the identity of a user. In other words, it takes care of logging in and identify the users (in this case, the ESP32). Knowing a user’s identity allows an app to securely save user data in the cloud and provide the same personalized experience across all of the user’s devices.” To learn more about the authentication methods, you can [read the documentation](https://firebase.google.com/docs/auth).

**`26.`** Click on "**`Authentication`**" in the Firebase console to set up user sign-in options for your app.

![1](images/49.png)

**`27.`** Click on "**`Authentication`**" in the Firebase console sidebar to access authentication settings

**`28.`** Click the "**`Get started`**" button to begin setting up user authentication for your project.

![1](images/50.png)


**`29.`** Select "**`Email/Password`**" as the sign-in method to enable users to authenticate using their email address and password.

![1](images/51.png)

**`30.`** Toggle the "**`Enable`**" switch to activate email/password sign-in authentication.

**`31.`** Click the "**`Save`**" button to apply and confirm the changes.

![1](images/52.png)

**`32.`** The "**`Email/Password`**" sign-in provider is enabled, allowing users to authenticate using their email and password.

![1](images/53.png)

**`33.`** Click on the "**`Users`**" tab to manage user authentication settings.

**`34.`** Click the "**`Add user`**" button to add a new user to the project.

![1](images/54.png)

**`35.`** Enter the **`email`** and **`password`** for the new user in the respective fields.

**`36.`** Click the "**`Add user`**" button to create and add the new user to the project.

![1](images/55.png)

**`37.`** This section displays the list of registered users, showing their email addresses, creation date, and user UID.

![1](images/56.png)

* "Sign-in providers section showing **`Email/Password`** provider **`enabled`** for authentication."

![image](https://github.com/user-attachments/assets/4d619979-efce-453c-af00-057dbdcea278)

## VIII. CREATING A REAL-TIME DATABASE

The next step is creating a Realtime Database for your project. Follow the next steps to create the database.

**`38.`** Selection of the "**`Realtime Database`**" option from the Firebase console menu, used to manage real-time data storage and synchronization.

**`39.`** Button labeled "**`Create Database`**" which initiates the process of setting up a new Firebase Realtime Database.

![1](images/57.png)

**`40.`** The "**`Create Database`**" button, which is clicked to initiate setting up a new Firebase Realtime Database.

**`41.`** The "**`Realtime Database location`**" dropdown menu, where the user selects the desired region for storing the database, currently set to "**`Singapore (asia-southeast1)`**."

![1](images/58.png)

**`42.`**  The option to "**`Start in test mode`**," which allows the database to be open by default with open access for testing purposes.

**`43.`** The security rules code snippet that defines the database's read and write permissions during test mode, allowing access for 30 days.

**`44.`** The "**`Enable`**" button to activate the security rules, applying the configured permissions to the Firebase Realtime Database

* Set up security rules for your database. For testing purposes, select Start in test mode. In later tutorials you’ll learn how to secure your database using database rules.

![1](images/59.png)

**`45.`** The "**`Realtime Database`**" option selected in the Firebase console, which allows you to view and manage your real-time database settings and data.

**`46.`** The "**`Data`**" tab within the Realtime Database section, providing access to the database's data structure and content.

**`47.`** The URL link to the live instance of the Firebase Realtime Database, which can be shared or used to access the database directly.

* Your database is now created. You need to copy and save the database URL—highlighted in the following image—because you’ll need it later in your ESP32 code.

![1](images/60.png)

The Realtime Database is all set. Now, you also need to get your project API key.

## IX. GET THE PROJECT API KEY

**1.** To get your project’s API key, on the left sidebar click on **Project Settings**.

![image](https://github.com/user-attachments/assets/87f75a29-af7e-4426-9484-a20718254df4)


**2.** Copy the API Key to a safe place because you’ll need it later.

![image](https://github.com/user-attachments/assets/67a056e6-c7a1-4bca-aae7-b330de8a404c)


Now, you have everything ready to interface the ESP32 with the database.

## X. SETUP RULES

**`48.`** The "**`Rules`**" tab selected in the Firebase Realtime Database, where security rules are configured to control data access.

**`49.`** The code editor displaying the security rules written in JSON, defining read and write permissions for the "**`usersData`**" node based on user authentication.

**`50.`** The "**`Publish`**" button used to save and apply the updated security rules to the Firebase Realtime Database.

![1](images/61.png)

The **`Rules`** section of the Firebase Realtime Database. Here’s a breakdown of what this section entails and its purpose:

**Components:**

 **1. Rules Structure:**

 * The rules defined in this section dictate how data can be accessed and modified within your Realtime Database. They are written in a JSON-like syntax.

 **2. Root Object:**

 * The outer curly braces **`{}`** encapsulate the entire set of rules. This is where you define various rules and conditions.

 **3. UserData Path:**

 * The **`"UserData"`** key indicates that these rules are intended for a specific path in your database where user-related data is stored. This organizes the rules based on the functionality of the stored data.

 **4. Dynamic User ID (**`$uid`**) Placeholder:**

 * The `**"$uid"**` placeholder is a dynamic variable that represents the unique identifier for each user. This means the rules can apply to multiple users based on their unique IDs.

 **5. Read and Write Permissions:**

 * Under each user’s ID (specifically **`"$uid"`**), the **`.read`** and **`.write`** keys define the permissions:
   * **`".read": "$uid === auth.uid"`**: This rule allows reading data only if the user’s ID matches the authenticated user's ID. In other words, a user can read their own data.
   * **`".write": "$uid === auth.uid"`**: Similarly, this rule allows writing data only if the user’s ID matches the authenticated user's ID, meaning they can only modify their own data.
  
**Purpose:**

 **1. Data Security:**

 * These rules are crucial for securing your database. By allowing users to access only their own data, you prevent unauthorized access and modifications by other users.

 **2. User-Level Data Management:**

 * The structure enables users to store private data without risking exposure to other users of the application.

![image](https://github.com/user-attachments/assets/3dc93e0b-3943-486c-9e51-b1188674d2bc)


 **6. JSON:**

```json
{
    "rules": {
        "UsersData": {
            "$uid": {
                ".read": "$uid === auth.uid",
                ".write": "$uid === auth.uid"
            }
        }
    }
}
```

The JSON structure you've provided outlines the rules for accessing the **`UsersData`** path in a Firebase Realtime Database. Below, I’ll explain the different components of the structure, ensuring clarity regarding its purpose and function.

**JSON Structure Breakdown:**

 **1. Outer Object (**`rules`**):**

 * The outermost curly braces **`{}`** create the root object for your rules. This is where all the database access rules are defined.

 **2. Path to Specific Data (**`UsersData`**):**

 * The **`"UsersData"`** key designates a specific path in the database where user-related data will be stored.

 **3. Dynamic User ID (**`$uid`**):**

 * **`"$uid"`** is a placeholder that represents individual user IDs. This allows the rules to apply dynamically based on the ID of the user interacting with the database.

 **4. Read Permission (**`.read`**):**

 * The rule **`.read: "$uid === auth.uid"`** means that a user can read the data at the path corresponding to their unique user ID only if that user's ID matches the ID of the authenticated user **`(auth.uid)`**.
 * This ensures that users can only access their own data, which enhances security and privacy.

 **5. Write Permission (**`.write`**):**

 * Similarly, the rule **`.write: "$uid === auth.uid"`** restricts write access to the data at that path. Users can only write (or modify) data if their user ID matches auth.uid, ensuring they can only edit their own information.
   
