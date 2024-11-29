#pragma once
#include <exception>
namespace Engine {
class font_not_found : public std::exception {};
class not_found : public std::exception {};
class render_error : public std::exception {};
class no_surface : public render_error {};
class surface_to_texture : public render_error {};

} // namespace Engine
