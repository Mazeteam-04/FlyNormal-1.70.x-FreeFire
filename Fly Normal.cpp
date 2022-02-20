"MAZETEAMSB_0_2",//0



bool Gravidade = false;
bool verificacao = false;
int velocidade = 0;
int conttelekill = 1;
bool FlyAltura = false;
float TFPosX = 0.0f;
float TFPosY = 0.0f;
float TFPosZ = 0.0f;
void *TFPos = nullptr;



case 0:
if (Value > 0) { 
    FlyAltura = true; 
    velocidade =  (int)Value; 
    } else { 
    FlyAltura = false; 
    velocidade = 0; 
    }
break;
    


void (*UpdateFly)(void* updatedoflyfds);
void _UpdateFly(void* updatedoflyfds) {
    if(UpdateFly) {
        void *Match = Curent_Match();
        if((FlyAltura) && Match) { 
            void* LocalPlayer = GetLocalPlayer(Match);
            if(FlyAltura && LocalPlayer){
                Gravidade = true;
                conttelekill = 0;              
                void *_MountTF = Component_GetTransform(LocalPlayer);
                if (_MountTF != NULL) {
                    Vector3 MountTF =
                            Transform_INTERNAL_GetPosition(_MountTF);
                    if(velocidade == 1 || (TFPosX == 0.0f || TFPosY == 0.0f || TFPosZ == 0.0f || TFPos == nullptr)){
                        if(TFPosX == 0.0f || TFPosZ == 0.0f || TFPos == nullptr){
                            TFPosX = MountTF.X;
                            TFPosZ = MountTF.Z;
                            TFPos = LocalPlayer;
                        }
                        TFPosY = MountTF.Y;
                    }
                    if(velocidade > 0 && velocidade < 2){
                        verificacao = true;
                        Transform_INTERNAL_SetPosition(Component_GetTransform(LocalPlayer), Vvector3(MountTF.X, MountTF.Y + 000.1f, MountTF.Z));
                    }else if(velocidade == 2){
                        verificacao = false;
                        Transform_INTERNAL_SetPosition(Component_GetTransform(LocalPlayer), Vvector3(MountTF.X, TFPosY, MountTF.Z));
                    }
                }
            }else{
                verificacao = false;
                ++conttelekill;
                if(conttelekill > 3000){
                    Gravidade = false;
                }
                TFPosX = 0.0f;
                TFPosY = 0.0f;
                TFPosZ = 0.0f;
                TFPos = nullptr;
            }
        }
    }
    UpdateFly(updatedoflyfds);
}
    
    


bool (*TrocarArma)(void* _this);
bool _TrocarArma(void* _this) {
    if(FlyAltura){
        return true;
    }
    return TrocarArma(_this);
}

bool (*IsIgnoreHighFalling)(void* player);
bool _IsIgnoreHighFalling(void* player) {
    if (Gravidade) {
        return true;
    }
    return IsIgnoreHighFalling(player);
}

int (*GetPhysXState)(void* player);
int _GetPhysXState(void* player) {
    if (verificacao) {
        return 0;
    }
    return GetPhysXState(player);
}



float (*GravidadeOn)(void* player);
float _GravidadeOn(void* player) {
    if (FlyAltura) {
        return -599999.0f -599999.0f -599999.0f;
    }
    return GravidadeOn(player);
}





HOOK(0xB7BA9C, _UpdateFly, UpdateFly);//2 public virtual void UpdateBehavior(float OPKNJGBDOBB, float OMAFEKBHOAA) { }
HOOK(0xB58A7C, _TrocarArma, TrocarArma);//public bool IsCatapultFalling() { }
HOOK(0x210F1D4,_GravidadeOn, GravidadeOn);
HOOK(0xBC5FB8, _IsIgnoreHighFalling, IsIgnoreHighFalling);//public virtual bool IsIgnoreHighFalling() { }
HOOK(0xB533AC, _GetPhysXState, GetPhysXState);//public bool get_IsParachuting() { }
HOOK(0xBCED78, _TrocarArma, TrocarArma);//public bool IsFoldWingGliding() { }
HOOK(0xBDA020, _FlyAr, FlyAr); //1.70 public virtual bool IsJumpCanMove() { }
    