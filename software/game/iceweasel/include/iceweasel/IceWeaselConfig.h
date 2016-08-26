#pragma once

#include <Urho3D/Core/Object.h>


namespace Urho3D {
    class Context;
    class XMLFile;
}


class IceWeaselConfig : public Urho3D::Object
{
    URHO3D_OBJECT(IceWeaselConfig, Urho3D::Object)

public:

    struct Data {
        struct PlayerClass {
            Urho3D::String className;
            struct Body {
                float width, height, mass;
            } body;
            struct Jump {
                float force, bunnyHopBoost;
            } jump;
            struct Speed {
                float crawl, walk, run;
            } speed;
        };
        struct FreeCam {
            struct Speed {
                float normal, fast, smoothness;
            } speed;
        } freeCam;
        Urho3D::Vector<PlayerClass> playerClass;
    };

    IceWeaselConfig(Urho3D::Context* context);

    void Load(Urho3D::String fileName);
    void LoadXML(Urho3D::XMLFile* xml);
    void Reload();

    const Data& GetConfig() const;

private:
    void HandleFileChanged(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

    Urho3D::SharedPtr<Urho3D::XMLFile> xml_;
    Data data_;
};