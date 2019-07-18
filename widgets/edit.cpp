#include "core_include/api.h"
#include "core_include/rect.h"
#include "core_include/cmd_target.h"
#include "core_include/wnd.h"
#include "core_include/resource.h"
#include "core_include/word.h"
#include "core_include/surface.h"
#include "core_include/theme.h"
#include "../widgets_include/button.h"
#include "../widgets_include/label.h"
#include "../widgets_include/keyboard.h"
#include "../widgets_include/edit.h"
#include "../widgets_include/keyboard.h"
#include <string.h>

#define IDD_KEY_BOARD		0x1

GL_BEGIN_MESSAGE_MAP(c_edit)
ON_KEYBORAD_UPDATE(IDD_KEY_BOARD, c_edit::on_key_board_click)
GL_END_MESSAGE_MAP()

static c_keyboard  s_keyboard;

void c_edit::pre_create_wnd()
{
	m_attr = (WND_ATTRIBUTION)(ATTR_VISIBLE | ATTR_FOCUS);
	m_kb_style = STYLE_ALL_BOARD;
	m_font_type = c_theme::get_font(FONT_DEFAULT);
	m_font_color = c_theme::get_color(COLOR_WND_FONT);

	memset(m_str_input, 0, sizeof(m_str_input));
	memset(m_str, 0, sizeof(m_str));
	set_text(c_wnd::m_str);
}

void c_edit::set_text(const char* str)
{
	if (str != 0 && strlen(str) < sizeof(m_str))
	{
		strcpy(m_str, str);
	}
}

bool c_edit::on_touch(int x, int y, TOUCH_ACTION action)
{
	(action == TOUCH_DOWN) ? on_touch_down(x, y) : on_touch_up(x, y);
	return true;
}

void c_edit::on_touch_down(int x, int y)
{
	c_rect kb_rect_relate_2_edit_parent;
	s_keyboard.get_wnd_rect(kb_rect_relate_2_edit_parent);
	kb_rect_relate_2_edit_parent.m_left += m_wnd_rect.m_left;
	kb_rect_relate_2_edit_parent.m_right += m_wnd_rect.m_left;
	kb_rect_relate_2_edit_parent.m_top += m_wnd_rect.m_top;
	kb_rect_relate_2_edit_parent.m_bottom += m_wnd_rect.m_top;

	if (m_wnd_rect.PtInRect(x, y))
	{//click edit box
		if (STATUS_NORMAL == m_status)
		{
			m_parent->set_child_focus(this);
		}
	}
	else if (kb_rect_relate_2_edit_parent.PtInRect(x,y))
	{//click key board
        c_wnd::on_touch(x, y, TOUCH_DOWN);
	}
	else
	{
		if (STATUS_PUSHED == m_status)
		{
			m_status = STATUS_FOCUSED;
			on_paint();
		}        
	}
}

void c_edit::on_touch_up(int x, int y)
{
	if (STATUS_FOCUSED == m_status)
	{
		m_status = STATUS_PUSHED;
		on_paint();
	}
	else if (STATUS_PUSHED == m_status)
	{
		if (m_wnd_rect.PtInRect(x,y))
		{//click edit box
			m_status = STATUS_FOCUSED;
			on_paint();
		}
		else
		{
			c_wnd::on_touch(x, y, TOUCH_UP);
		}
	}
}

void c_edit::on_focus()
{
	m_status = STATUS_FOCUSED;
	on_paint();
}

void c_edit::on_kill_focus()
{
	m_status = STATUS_NORMAL;
	on_paint();
}

void c_edit::on_paint()
{
	c_rect rect;
	get_screen_rect(rect);
	c_rect empty_rect;
	empty_rect.Empty();
	switch(m_status)
	{
	case STATUS_NORMAL:
		if (m_z_order > m_parent->get_z_order())
		{
			s_keyboard.disconnect();
			m_surface->set_frame_layer_visible_rect(empty_rect, s_keyboard.get_z_order());
			m_z_order = m_parent->get_z_order();
			m_attr = (WND_ATTRIBUTION)(ATTR_VISIBLE | ATTR_FOCUS);
		}
		m_surface->fill_rect(rect, c_theme::get_color(COLOR_WND_NORMAL), m_z_order);
		c_word::draw_string_in_rect(m_surface, m_parent->get_z_order(), m_str, rect, m_font_type, m_font_color, c_theme::get_color(COLOR_WND_NORMAL), ALIGN_HCENTER | ALIGN_VCENTER);
		break;
	case STATUS_FOCUSED:
		if (m_z_order > m_parent->get_z_order())
		{
			s_keyboard.disconnect();
			m_surface->set_frame_layer_visible_rect(empty_rect, s_keyboard.get_z_order());
			m_z_order = m_parent->get_z_order();
			m_attr = (WND_ATTRIBUTION)(ATTR_VISIBLE | ATTR_FOCUS);
		}
		m_surface->fill_rect(rect, c_theme::get_color(COLOR_WND_FOCUS), m_z_order);
		c_word::draw_string_in_rect(m_surface, m_parent->get_z_order(), m_str, rect, m_font_type, m_font_color, c_theme::get_color(COLOR_WND_FOCUS), ALIGN_HCENTER | ALIGN_VCENTER);
		break;
	case STATUS_PUSHED:
		if (m_z_order == m_parent->get_z_order())
		{
			m_z_order++;
			m_attr = (WND_ATTRIBUTION)(ATTR_VISIBLE | ATTR_FOCUS | ATTR_MODAL);
			show_keyboard();
		}
		m_surface->fill_rect(rect.m_left, rect.m_top, rect.m_right, rect.m_bottom, c_theme::get_color(COLOR_WND_PUSHED), m_parent->get_z_order());
		m_surface->draw_rect(rect.m_left, rect.m_top, rect.m_right, rect.m_bottom, c_theme::get_color(COLOR_WND_BORDER), m_parent->get_z_order(), 2);
		strlen(m_str_input) ? c_word::draw_string_in_rect(m_surface, m_parent->get_z_order(), m_str_input, rect, m_font_type, m_font_color, c_theme::get_color(COLOR_WND_PUSHED), ALIGN_HCENTER | ALIGN_VCENTER) :
			c_word::draw_string_in_rect(m_surface, m_parent->get_z_order(), m_str, rect, m_font_type, m_font_color, c_theme::get_color(COLOR_WND_PUSHED), ALIGN_HCENTER | ALIGN_VCENTER);
		break;
	default:
		ASSERT(false);
	}
}

void c_edit::show_keyboard()
{
	s_keyboard.connect(this, IDD_KEY_BOARD, m_kb_style);

	c_rect kb_rect;
	s_keyboard.get_screen_rect(kb_rect);
	m_surface->set_frame_layer_visible_rect(kb_rect, s_keyboard.get_z_order());
	s_keyboard.show_window();
}

void c_edit::on_key_board_click(unsigned int ctrl_id, long param)
{
	switch (param)
	{
	case CLICK_CHAR:
		strcpy(m_str_input, s_keyboard.get_str());
		on_paint();
		break;
	case CLICK_ENTER:
		if (strlen(m_str_input))
		{
			memcpy(m_str, m_str_input, sizeof(m_str_input));
		}
		m_status = STATUS_FOCUSED;
		on_paint();
		break;
	case CLICK_ESC:
		memset(m_str_input, 0, sizeof(m_str_input));
		m_status = STATUS_FOCUSED;
		on_paint();
		break;
	default:
		ASSERT(false);
		break;
	}
}
