/*
	Files.h
	 Definitions of file structures
*/

// POPS.CFG - unused but left for reference
const unsigned char magic_1[4] = {0x50, 0x4F, 0x50, 0x53};
const unsigned char magic_2[4] = {0x2E, 0x43, 0x46, 0x47};

/* enums and structs courtesy of The FloW */
enum PopsButtonAssignments {
	POPS_BUTTON_ASSIGN_UP,
	POPS_BUTTON_ASSIGN_DOWN,
	POPS_BUTTON_ASSIGN_LEFT,
	POPS_BUTTON_ASSIGN_RIGHT,
	POPS_BUTTON_ASSIGN_TRIANGLE,
	POPS_BUTTON_ASSIGN_CIRCLE,
	POPS_BUTTON_ASSIGN_CROSS,
	POPS_BUTTON_ASSIGN_SQUARE,
	POPS_BUTTON_ASSIGN_L,
	POPS_BUTTON_ASSIGN_R,
	POPS_BUTTON_ASSIGN_L_UP,
	POPS_BUTTON_ASSIGN_L_DOWN,
	POPS_BUTTON_ASSIGN_L_LEFT,
	POPS_BUTTON_ASSIGN_L_RIGHT,
	POPS_BUTTON_ASSIGN_R_UP,
	POPS_BUTTON_ASSIGN_R_DOWN,
	POPS_BUTTON_ASSIGN_R_LEFT,
	POPS_BUTTON_ASSIGN_R_RIGHT,
	POPS_BUTTON_ASSIGN_NUMBERS,
};

enum PopsTouchAssignments {
	POPS_TOUCH_ASSIGN_TOP_LEFT,
	POPS_TOUCH_ASSIGN_TOP_RIGHT,
	POPS_TOUCH_ASSIGN_BOTTOM_LEFT,
	POPS_TOUCH_ASSIGN_BOTTOM_RIGHT,
	POPS_TOUCH_ASSIGN_NUMBERS,
};

typedef struct {
	int32_t x; // 0x00
	int32_t y; // 0x04
	int32_t width; // 0x08
	int32_t height; // 0x0C
} PopsCustomScreen; // 0x10

// __sce_menuinfo structure
typedef struct {
	uint32_t magic_1; // 0x00
	uint32_t magic_2; // 0x04
	int32_t version; // 0x08
	int32_t unk; // 0x0C
	int32_t disc_load_speed; // 0x10
	int32_t volume_level; // 0x14
	int32_t controller_number; // 0x18
	uint16_t controller_mode; // 0x1C
	uint32_t buttons_assignment_mode; // 0x1E
	int32_t use_bilinear_filtering; // 0x20
	int32_t screen_mode; // 0x24
	PopsCustomScreen custom_screen; // 0x28 
	uint8_t button_assignment[POPS_BUTTON_ASSIGN_NUMBERS]; // 0x38
	uint8_t front_touch_assignment[POPS_TOUCH_ASSIGN_NUMBERS]; // 0x4A
	uint8_t back_touch_assignment[POPS_TOUCH_ASSIGN_NUMBERS]; // 0x4E
} PopsConfiguration; // 0x400