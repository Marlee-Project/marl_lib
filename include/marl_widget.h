#ifndef MARL_WIDGET_H
#define MARL_WIDGET_H

#include "marl_lib.h"

typedef enum MARL_WidgetType {
	MARL_WIDGET_TEXTBOX = 0x1,
	MARL_WIDGET_BUTTON
} MARL_WidgetType;

typedef struct MARL_WidgetInfo {
	MARL_WidgetType type;
	MARL_Rect bounds;
	SDL_Texture *texture;
	char update: 1;
} MARL_WidgetInfo;

typedef struct MARL_TextBox {
	MARL_WidgetInfo info;
	const char* content;
	TTF_Font *font;
} MARL_TextBox;

typedef struct MARL_Button {
	MARL_WidgetInfo *info;
} MARL_Button;

typedef union MARL_Widget {
	MARL_WidgetInfo *info;
	MARL_TextBox *textbox;
	MARL_Button *button;
} MARL_Widget;

MARL_Widget MARL_CreateWidget(MARL_WidgetType type, int x, int y, int w, int h);
MARL_Widget MARL_CreateTextBox(const char *content, TTF_Font *font, int x, int y, int w, int h);
MARL_Widget MARL_CreateButton();

void MARL_WidgetDraw(MARL_Window *window, MARL_Widget widget);
void MARL_TextBoxDraw(MARL_Window *window, MARL_TextBox *textBox);
void MARL_ButtonDraw(MARL_Window *window, MARL_Button *button);

void MARL_WidgetUpdate(MARL_Widget widget);

void MARL_TextBoxSetFont(TTF_Font *font);
void MARL_TextBoxSetContent(const char *content);

void MARL_WidgetDestroy(MARL_Widget widget);
void MARL_TextBoxDestroy(MARL_TextBox *textbox);
void MARL_ButtonDestroy(MARL_Button *button);

#endif // MARL_WIDGET_H
