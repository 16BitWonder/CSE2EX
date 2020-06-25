#include "../OpenGL.h"

#include <stddef.h>
#include <string>

#include <glad/glad.h>
#include "SDL.h"

#include "../../../Misc.h"

bool WindowBackend_OpenGL_CreateWindow(const char *window_title, int *screen_width, int *screen_height, bool fullscreen)
{
	if (SDL_SetVideoMode(*screen_width, *screen_height, 0, SDL_RESIZABLE | SDL_OPENGL | (fullscreen ? SDL_FULLSCREEN : 0)) != NULL)
	{
		SDL_WM_SetCaption(window_title, NULL);

		if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			// Check if the platform supports OpenGL 3.2
			if (GLAD_GL_VERSION_3_2)
			{
				Backend_PostWindowCreation();

				return true;
			}
			else
			{
				Backend_ShowMessageBox("Fatal error (OpenGL rendering backend)", "Your system does not support OpenGL 3.2");
			}
		}
		else
		{
			Backend_ShowMessageBox("Fatal error (OpenGL rendering backend)", "Couldn't load OpenGL functions");
		}
	}
	else
	{
		std::string error_message = std::string("Could not create window: ") + SDL_GetError();
		Backend_ShowMessageBox("Fatal error (OpenGL rendering backend)", error_message.c_str());
	}

	return false;
}

void WindowBackend_OpenGL_DestroyWindow(void)
{
}

void WindowBackend_OpenGL_Display(void)
{
	SDL_GL_SwapBuffers();
}
