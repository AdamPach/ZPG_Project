#pragma once

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

#define DEFAULT_CAMERA_X 0.0f
#define DEFAULT_CAMERA_Y 0.0f
#define DEFAULT_CAMERA_Z 3.0f

#define DEFAULT_SPEED 0.4f
#define DEFAULT_SENSITIVITY 0.2f

#define GPU_SHADER_PATH "./gpu_shaders/"
#define TEXTURE_PATH "./assets/textures/"
#define MODELS_PATH "./assets/models/"

#define DEFAULT_VIEW_MATRIX_NAME "viewMatrix"
#define DEFAULT_PROJECTION_MATRIX_NAME "projectionMatrix"

#define DEFAULT_LIGHT_TYPE_NAME "lightType"
#define DEFAULT_LIGHT_POSITION_NAME "lightPosition"
#define DEFAULT_LIGHT_COLOR_NAME "lightColor"
#define DEFAULT_SPOT_LIGHT_DIRECTION_NAME "lightDirection" // For spot light, determines a direction of the light
#define DEFAULT_SPOT_LIGHT_CUT_OFF_NAME "cutOff"
#define DEFAULT_SPOT_LIGHT_OUTER_CUT_OFF_NAME "outerCutOff"

#define DEFAULT_MODEL_MATRIX_NAME "modelMatrix"
#define DEFAULT_CAMERA_POSITION_NAME "cameraPosition"
#define DEFAULT_MATERIAL_COLOR_NAME "materialColor"
#define DEFAULT_LIGHTS_COUNT_NAME "lightsCount"
#define DEFAULT_TEXTURE_UNIT_NAME "textureUnitID"

#define DEFAULT_LIGHTS_NAME "lights"