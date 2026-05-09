// HALLSCAN KEYMAP - MUX Channel to Sensor Mappings
// This file defines which sensor is connected to which MUX channel

#include "hallscan_config.h"

// ========================================
// MUX CHANNEL MAPPINGS
// ========================================
// Each mux16_ref_t array maps 16 MUX channels (0-15) to sensor IDs
// Use 0 for unmapped channels

#ifdef RIGHT_TEST
// MUX 1 - Connected to MUX1_ADC_PIN
const mux16_ref_t mux1_channels[16] = {
	[0]  = { 0 },
	[1]  = { 0 },
	[2]  = { 0 },
	[3]  = { S_COMM },
	[4]  = { S_E },
	[5]  = { S_U },
	[6]  = { 0 },
	[7]  = { 0 },
	[8]  = { S_Y },
	[9]  = { S_APOS },
	[10] = { S_O },
	[11] = { 0 },
	[12] = { 0 },
	[13] = { S_SLASH },
	[14] = { S_I },
	[15] = { S_DOT },
};

// MUX 2 - Connected to MUX2_ADC_PIN
const mux16_ref_t mux2_channels[16] = {
	[0]  = { 0 },
	[1]  = { 0 },
	[2]  = { 0 },
	[3]  = { S_H },
	[4]  = { S_J },
	[5]  = { S_K },
	[6]  = { 0 },
	[7]  = { 0 },
	[8]  = { S_L },
	[9]  = { S_N },
	[10] = { S_M },
	[11] = { 0 },
	[12] = { 0 },
	[13] = { S_BSPC },
	[14] = { S_ENT },
	[15] = { S_DEL },
};
#else
// MUX 1 - Connected to MUX1_ADC_PIN
const mux16_ref_t mux1_channels[16] = {
	[0]  = { S_X },
	[1]  = { S_R },
	[2]  = { S_W },
	[3]  = { 0 },
	[4]  = { 0 },
	[5]  = { S_Z },
	[6]  = { S_A },
	[7]  = { S_Q },
	[8]  = { 0 },
	[9]  = { 0 },
	[10] = { S_F },
	[11] = { S_S },
	[12] = { S_C },
	[13] = { 0 },
	[14] = { 0 },
	[15] = { 0 },
};

// MUX 2 - Connected to MUX2_ADC_PIN
const mux16_ref_t mux2_channels[16] = {
	[0]  = { S_TAB },
	[1]  = { S_SPC },
	[2]  = { S_ESC },
	[3]  = { 0 },
	[4]  = { 0 },
	[5]  = { S_V },
	[6]  = { S_T },
	[7]  = { S_P },
	[8]  = { 0 },
	[9]  = { 0 },
	[10] = { S_B },
	[11] = { S_D },
	[12] = { S_G },
	[13] = { 0 },
	[14] = { 0 },
	[15] = { 0 },
};
#endif

// // MUX 3 - Connected to MUX3_ADC_PIN
// const mux16_ref_t mux3_channels[16] = {
// 	[0]  = { 0 },
// 	[1]  = { 0 },
// 	[2]  = { 0 },
// 	[3]  = { S_D },
// 	[4]  = { S_R },
// 	[5]  = { 0 },
// 	[6]  = { S_F },
// 	[7]  = { S_G },
// 	[8]  = { 0 },
// 	[9]  = { 0 },
// 	[10] = { S_H },
// 	[11] = { S_J },
// 	[12] = { 0 },
// 	[13] = { 0 },
// 	[14] = { S_K },
// 	[15] = { S_L },
// };

// // MUX 4 - Connected to MUX4_ADC_PIN
// const mux16_ref_t mux4_channels[16] = {
// 	[0]  = { 0 },
// 	[1]  = { 0 },
// 	[2]  = { 0 },
// 	[3]  = { 0 },
// 	[4]  = { 0 },
// 	[5]  = { S_SPC1 },
// 	[6]  = { S_M },
// 	[7]  = { S_B },
// 	[8]  = { S_N },
// 	[9]  = { S_C },
// 	[10] = { 0 },
// 	[11] = { S_V },
// 	[12] = { S_COMM },
// 	[13] = { 0 },
// 	[14] = { 0 },
// 	[15] = { 0 },
// };

// -------------------------------------
// ----------     MUX 5     ------------
// -------------------------------------
// MUX5 disabled for now (external MCP3208)
/*
const mux16_ref_t mux5_channels[16] = {
	[0]  = { 0 },
	[1]  = { 0 },
	[2]  = { 0 },
	[3]  = { S_DOT },
	[4]  = { S_SCLN },
	[5]  = { 0 },
	[6]  = { S_DOWN },
	[7]  = { S_RGHT },
	[8]  = { 0 },
	[9]  = { 0 },
	[10] = { S_UP },
	[11] = { S_LEFT },
	[12] = { 0 },
	[13] = { 0 },
	[14] = { S_SPC2 },
	[15] = { S_LALT },
};
*/
