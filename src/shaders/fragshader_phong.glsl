#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertNormal;
in vec3 P;
in vec2 texCoord;

uniform sampler2D textureSampler;

// Specify material properties
const float ka = 0.4;
const float kd = 0.4;
const float ks = 0.4;
const float specularExp = 8.0;
const vec3 materialColor = vec3(1.0,1.0,1.0);

// Specify light properties
const vec3 lightPosition = vec3(100.0,50.0,0.0);
const vec3 lightColor = vec3(1.0,1.0,1.0);

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;

void main() {
    vec3 texColor = texture(textureSampler, texCoord).rgb;

    // Get the necessary directions for the illumination components
    vec3 N = normalize(vertNormal);
    vec3 L = normalize(lightPosition - P);
    vec3 V = normalize(vec3(0.0,0.0,0.0) - P);
    vec3 R = normalize(reflect(-L, N));

    // Illumination components computation 
    vec3 ambientComp = ka * materialColor * texColor.rgb;
    vec3 diffuseComp = kd * max(0.0, dot(N, L)) * texColor.rgb * lightColor;
    vec3 specularComp = ks * pow(max(0.0, dot(R,V)), specularExp) * lightColor;

    // Set shader output to the computed color
    fColor = vec4(ambientComp + diffuseComp + specularComp, 1.0);
}
