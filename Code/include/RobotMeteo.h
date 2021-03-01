#pragma once

#include "ModuleCapteurs.h"
#include "ModuleConnexion.h"

class RobotMeteo
{
    public:
    ModuleCapteurs m_Capteurs;
    ModuleConnexion m_Connexion;

    RobotMeteo();
    void Chargement();
    void Executer();
};