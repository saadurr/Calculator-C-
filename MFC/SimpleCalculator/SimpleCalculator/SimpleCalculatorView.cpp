
// SimpleCalculatorView.cpp : implementation of the CSimpleCalculatorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SimpleCalculator.h"
#endif

#include "SimpleCalculatorDoc.h"
#include "SimpleCalculatorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleCalculatorView

IMPLEMENT_DYNCREATE(CSimpleCalculatorView, CView)

BEGIN_MESSAGE_MAP(CSimpleCalculatorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSimpleCalculatorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSimpleCalculatorView construction/destruction

CSimpleCalculatorView::CSimpleCalculatorView() noexcept
{
	// TODO: add construction code here

}

CSimpleCalculatorView::~CSimpleCalculatorView()
{
}

BOOL CSimpleCalculatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimpleCalculatorView drawing

void CSimpleCalculatorView::OnDraw(CDC* /*pDC*/)
{
	CSimpleCalculatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSimpleCalculatorView printing


void CSimpleCalculatorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSimpleCalculatorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimpleCalculatorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimpleCalculatorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSimpleCalculatorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSimpleCalculatorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSimpleCalculatorView diagnostics

#ifdef _DEBUG
void CSimpleCalculatorView::AssertValid() const
{
	CView::AssertValid();
}

void CSimpleCalculatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleCalculatorDoc* CSimpleCalculatorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleCalculatorDoc)));
	return (CSimpleCalculatorDoc*)m_pDocument;
}
#endif //_DEBUG


// CSimpleCalculatorView message handlers
