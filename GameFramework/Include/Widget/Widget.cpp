
#include "Widget.h"
#include "WidgetWindow.h"

CWidget::CWidget()	:
	m_Scene(nullptr),
	m_Owner(nullptr),
	m_ZOrder(0),
	m_MouseHovered(false)
{
}

CWidget::CWidget(const CWidget& widget)	:
	CRef(widget)
{
	m_ZOrder = widget.m_ZOrder;
	m_MouseHovered = widget.m_MouseHovered;
}

CWidget::~CWidget()
{
}

bool CWidget::Init()
{
	return true;
}

void CWidget::Update(float DeltaTime)
{
}

void CWidget::PostUpdate(float DeltaTime)
{
}

void CWidget::Render(HDC hDC, float DeltaTime)
{
}

void CWidget::Render(HDC hDC, const Vector2& Pos, float DeltaTime)
{
}

bool CWidget::CollisionMouse(const Vector2& Pos)
{
	Vector2	RenderPos = m_Pos + m_Owner->GetPos();

	if (Pos.x < RenderPos.x)
		return false;

	else if (Pos.x > RenderPos.x + m_Size.x)
		return false;

	else if (Pos.y < RenderPos.y)
		return false;

	else if (Pos.y > RenderPos.y + m_Size.y)
		return false;

	if (!m_MouseHovered)
		CollisionMouseHoveredCallback(Pos);

	return true;
}

void CWidget::CollisionMouseHoveredCallback(const Vector2& Pos)
{
	m_MouseHovered = true;
}

void CWidget::CollisionMouseReleaseCallback()
{
	m_MouseHovered = false;
}
