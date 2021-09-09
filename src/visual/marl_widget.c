#include "marl_lib.h"

MARL_Widget MARL_CreateWidget(MARL_WidgetType type, int x, int y, int w, int h) {
	MARL_Widget widget;
	widget.info = malloc(sizeof(MARL_WidgetInfo));
	widget.info->type = type;
	widget.info->bounds.x = x;
	widget.info->bounds.y = y;
	widget.info->bounds.w = w;
	widget.info->bounds.h = h;
	widget.info->update = 1;
	widget.info->texture = 0;
	return widget;
}

MARL_Widget MARL_CreateTextBox(const char *content, TTF_Font *font, int x, int y, int w, int h) {
	MARL_Widget widget = MARL_CreateWidget(MARL_WIDGET_TEXTBOX, x, y, w, h);
	widget.textbox->content = content;
	widget.textbox->font = font;
	return widget;
}

void MARL_WidgetDraw(MARL_Window *window, MARL_Widget widget) {
	if(!widget.info->texture) {
		widget.info->texture = SDL_CreateTexture(window->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, widget.info->bounds.w, widget.info->bounds.h );
	}
	if(widget.info->update) {
		switch(widget.info->type) {
			case MARL_WIDGET_TEXTBOX:
				MARL_TextBoxDraw(window, widget.textbox);
			break;
			default:
				printf("What do you want to paint?\n");
		
		}
	}
		
	SDL_RenderCopy(window->sdl_renderer, widget.info->texture, NULL, &widget.info->bounds);
}

void MARL_TextBoxDraw(MARL_Window *window, MARL_TextBox *textbox) {
	SDL_SetRenderTarget(window->sdl_renderer, textbox->info.texture);
	SDL_SetRenderDrawColor(window->sdl_renderer, 0, 0, 0, 255); // TODO make dev friendly :)
	SDL_RenderClear(window->sdl_renderer);

	SDL_Color tColor = {255, 127, 0, 255};
	SDL_Surface *tSurf = TTF_RenderText_Blended(textbox->font, textbox->content, tColor);
	SDL_Texture *tText = SDL_CreateTextureFromSurface(window->sdl_renderer, tSurf);
	SDL_FreeSurface(tSurf);
	MARL_Rect tRect;
	tRect.x = tRect.y = 0;
	SDL_QueryTexture(tText, NULL, NULL, &tRect.w, &tRect.h);
	SDL_RenderCopy(window->sdl_renderer, tText, NULL, &tRect);

	SDL_SetRenderTarget(window->sdl_renderer, NULL);
}
