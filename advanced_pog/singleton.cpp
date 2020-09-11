class singleton{
    static singleton* instance;
    singleton(){}
public:
    static singleton* GetInstance(){
        if(NULL == instance){
            instance = new singleton();
        }
        return instance;
    }
}

singleton* singleton::instance = NULL;