#include "AppFrame.h"

namespace LuaSTGPlus {
	void AppFrame::updateGraph2DBlendMode(BlendMode m)
	{
		if (m != m_Graph2DLastBlendMode)
		{
			m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_SRCALPHA;
			m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCALPHA;
			m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
			
			m_Graph2DBlendState.AlphaSrcBlend = F2DBLENDFACTOR_SRCALPHA;
			m_Graph2DBlendState.AlphaDestBlend = F2DBLENDFACTOR_INVSRCALPHA;
			m_Graph2DBlendState.AlphaBlendOp = F2DBLENDOPERATOR_ADD;

			m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_MODULATE;

			switch (m)
			{
			case BlendMode::AddAdd:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddAlpha:
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddSub:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_SUBTRACT;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddRev:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_REVSUBTRACT;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::MulAdd:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				break;
			case BlendMode::MulAlpha:
				break;
			case BlendMode::MulSub:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_SUBTRACT;
				break;
			case BlendMode::MulRev:
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_REVSUBTRACT;
				break;

			case BlendMode::MulMin:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_MIN;
				break;
			case BlendMode::MulMax:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_MAX;
				break;
			case BlendMode::MulMutiply:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ZERO;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_SRCCOLOR;
				break;
			case BlendMode::MulScreen:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCCOLOR;
				break;
			case BlendMode::AddMin:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_MIN;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddMax:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.BlendOp = F2DBLENDOPERATOR_MAX;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddMutiply:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ZERO;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_SRCCOLOR;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;
			case BlendMode::AddScreen:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCCOLOR;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ADD;
				break;

			case BlendMode::AlphaBal:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_INVDESTCOLOR;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCCOLOR;
				m_Graph2DColorBlendState = F2DGRAPH2DBLENDTYPE_ALPHATEXTURE;
				break;
			case BlendMode::One:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ZERO;
				m_Graph2DBlendState.AlphaSrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.AlphaDestBlend = F2DBLENDFACTOR_ZERO;
				break;

			default:
				break;
			}
			m_Graph2DLastBlendMode = m;
			m_Graph2D->SetBlendState(m_Graph2DBlendState);
			m_Graph2D->SetColorBlendType(m_Graph2DColorBlendState);
		}
	}

	void AppFrame::updateGraph3DBlendMode(BlendMode m)
	{
		if (m != m_Graph3DLastBlendMode)
		{
			m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_SRCALPHA;
			switch (m)
			{
			case BlendMode::AddAdd:
			case BlendMode::MulAdd:
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;
			case BlendMode::AddSub:
			case BlendMode::MulSub:
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCALPHA;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_SUBTRACT;
				break;
			case BlendMode::AddRev:
			case BlendMode::MulRev:
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCALPHA;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_REVSUBTRACT;
				break;
			case BlendMode::AddAlpha:
			case BlendMode::MulAlpha:
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCALPHA;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;

			case BlendMode::AddMin:
			case BlendMode::MulMin:
				m_Graph3DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_MIN;
				break;
			case BlendMode::AddMax:
			case BlendMode::MulMax:
				m_Graph3DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_MAX;
				break;
			case BlendMode::AddMutiply:
			case BlendMode::MulMutiply:
				m_Graph3DBlendState.SrcBlend = F2DBLENDFACTOR_ZERO;
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_SRCCOLOR;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;
			case BlendMode::AddScreen:
			case BlendMode::MulScreen:
				m_Graph3DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCCOLOR;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;

			case BlendMode::AlphaBal:
				m_Graph3DBlendState.SrcBlend = F2DBLENDFACTOR_INVDESTCOLOR;
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCCOLOR;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;
			case BlendMode::One:
				m_Graph2DBlendState.SrcBlend = F2DBLENDFACTOR_ONE;
				m_Graph2DBlendState.DestBlend = F2DBLENDFACTOR_ZERO;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;

			default:
				m_Graph3DBlendState.DestBlend = F2DBLENDFACTOR_INVSRCALPHA;
				m_Graph3DBlendState.BlendOp = F2DBLENDOPERATOR_ADD;
				break;
			}
			m_Graph3DLastBlendMode = m;
			m_Graph3D->SetBlendState(m_Graph3DBlendState);
		}
	}
};
