#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout(location = 0) in vec3 vertCoordinates_in;
layout(location = 1) in vec3 vertNormal_in;

// Specify the Uniforms of the vertex shader
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform mat3 normalTransform;

// Specify the output of the vertex stage
out vec3 vertNormal;
out vec3 P;

void main() {

    // Output computation of the phong vertex shader    
    gl_Position = projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0F);
    P = (modelViewTransform * vec4(vertCoordinates_in, 1.0)).xyz;
    vertNormal = normalize(normalTransform * vertNormal_in);
}
