# University_OpenGL_Project

##Output:
![image](https://github.com/rakib38324/University_OpenGL_Project/assets/108406603/2e359c01-cefe-4f23-889a-c9030615ffaf)

1. Introduction   
The goal of this project is to create a virtual university campus-like scenario using the OpenGL API (Open Graphics Library). The project involves developing a 2D environment showing various elements of a university campus, including university buildings, playgrounds, trees, sky, two buses, an airplane, a mosque, and the sun.   
2. Objectives   
The objectives of this project are as follows:  
	I use OpenGL to create visually appealing and interactive university campus environments.
	I design and model realistic academic buildings, playgrounds, trees, and other elements using appropriate 2D modeling software.
	I implement a dynamic lighting system to improve the visual realism of my scene.
	Include interactivity that allows users to explore the campus and interact with objects.
	Optimize the rendering process for best performance.    
3. Methodology   
The project follows the following methodology to achieve its objectives:  
3.1 Scene Setup  
•	Define the dimensions and layout of the university campus, including the position and orientation of different elements.  
•	Create a ground plane and texture it to represent different types of terrain, such as grass for the playground and pavement for pathways.  
•	Establish the position and movement of the camera to provide a suitable perspective for navigation.  
  
3.2 Modeling and Texturing  
•	Design and model the academic buildings, playground equipment, trees, bus, mosque, and other objects using 2D modeling software.  
•	Import the 2D models into the OpenGL project and position them within the campus scene.  
•	Apply appropriate textures and materials to the models to enhance their visual realism, such as brick textures for the buildings and bark textures for the trees.  
  
  
3.3 Lighting System  
•	Implement a dynamic lighting system using OpenGL's lighting functions.  
•	Define and position light sources, such as the sun and artificial lights, to create realistic lighting conditions in the scene.  
•	Adjust lighting properties, including intensity, color, and attenuation, to achieve the desired visual effects.  
  
3.4 Object Interaction  
•	Enable user interaction with the objects in the scene, such as selecting and moving the bus or rotating the airplane.  
•	Implement mechanisms for object selection, translation, and rotation using mouse and keyboard inputs.  
•	Provide visual feedback to users to indicate the selected objects or the result of interactions.  
  
3.5 Performance Optimization  
•	Optimize the rendering process to ensure smooth frame rates and efficient resource utilization.  
•	Implement techniques like frustum culling and level-of-detail rendering to improve performance.  
•	Profile the application and identify performance bottlenecks, optimizing critical sections of the code if necessary.  
  
4. Implementation  
The scene is implemented using the following steps:  
•	Create a scene graph. A scene graph is a data structure that represents the objects in the scene.  
•	Create a shader program. A shader program is a piece of code that is used to render the objects in the scene.  
•	Load the textures. The textures are used to provide the appearance of the objects in the scene.  
•	Render the scene. The scene is rendered by calling the OpenGL functions to draw the objects in the scene graph.  
