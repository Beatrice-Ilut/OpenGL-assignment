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

// Specify material properties
const float ka = 0.4;
const float kd = 0.4;
const float ks = 0.4;
const float specularExp = 8.0;
const vec3 materialColor = vec3(1.0,1.0,1.0);

// Specify light properties
const vec3 lightPosition = vec3(100.0,50.0,0.0);
const vec3 lightColor = vec3(1.0,1.0,1.0);

// Specify the output of the vertex stage
out vec3 color;

void main() {
    // gl_Position is the output (a vec4) of the vertex shader
    gl_Position = projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0F);

    // Get the surface point
    vec3 P = (modelViewTransform * vec4(vertCoordinates_in, 1.0)).xyz;

    // Get the necessary directions for the illumination components
    vec3 N = normalize(normalTransform * vertNormal_in);
    vec3 L = normalize(lightPosition - P);
    vec3 V = normalize(vec3(0,0,0) - P);
    vec3 R = normalize(reflect(-L, N));

    // Illumination components computation 
    vec3 ambientComp = ka * materialColor;
    vec3 diffuseComp = kd * max(0, dot(N, L)) * materialColor * lightColor;
    vec3 specularComp = ks * pow(max(0, dot(R,V)), specularExp) * lightColor;

    // Output of the vertex shader
    color = ambientComp + diffuseComp + specularComp;
}
