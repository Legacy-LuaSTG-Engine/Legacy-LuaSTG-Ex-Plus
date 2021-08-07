#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "E2DXAudio2Impl.hpp"

namespace Eyes2D {
	namespace Sound {
		class XAudio2VoicePool {
		private:
			IXAudio2* m_XAudio;                                              //ֻ�ǳ���
			IXAudio2MasteringVoice* m_MasteringVoice;                        //ֻ�ǳ���
			std::unordered_map<std::string, IXAudio2SubmixVoice*> m_MixVoice;//��������
			int m_TotalVoiceSpace;                                           //�ɱ䣬��Ƶ�أ�����ֵΪ64
			int m_NextAllocSpace;                                            //��һ�η����ID����������ֵΪ4
			std::vector<int> m_FreeVoiceID;                                  //���е���ƵID
			std::vector<IXAudio2SourceVoice*> m_SourceVoice;                 //��Դ��
		public:
			XAudio2VoicePool(IXAudio2* p, IXAudio2MasteringVoice* m);
			~XAudio2VoicePool();
		private:
			int allocID();
			void freeID(int id);
		public:
			IXAudio2SubmixVoice* CreateMixVoice(const std::string& name);
			IXAudio2SubmixVoice* GetMixVoice(const std::string& name);
			int                  CreateSourceVoice(const std::string& mixername, WAVEFORMATEX& format);
			IXAudio2SourceVoice* GetSourceVoice(int id);
			void                 DeleteSourceVoice(int id);
		};
	}
}
