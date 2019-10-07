//单例模式
//考虑线程安全

class CSingleton {

public:
	static CSingleton* GetInstance() {
		if (m_Instance == nullptr) {
			Lock();
			if (m_Instance == nullptr) {
				m_Instance = new CSingleton();
			}
			Unlock();
		}
		return m_Instance;
	}
	static void DestoryInstance() {
		if (m_Instance != nullptr) {
			delete m_Instance;
			m_Instance = nullptr;
		}
	}



private:
	CSingleton() {};
	static CSingleton* m_Instance;

};

CSingleton* CSingleton::m_Instance = nullptr;


