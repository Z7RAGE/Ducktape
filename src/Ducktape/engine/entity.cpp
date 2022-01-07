/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Ducktape/engine/entity.h>
using namespace DT;

Entity::Entity()
{
    isActive = true;
    layer = 0;
    tag = "Default";
    name = "New Entity";
    transform = AddComponent<Transform>();
}

Entity::Entity(std::string _name)
{
    isActive = true;
    layer = 0;
    tag = "Default";
    name = _name;
    transform = AddComponent<Transform>();
}

Entity::Entity(Vector2 pos, float rot, Vector2 scl)
{
    isActive = true;
    layer = 0;
    tag = "Default";
    name = "New Entity";
    transform = AddComponent<Transform>();
    transform->SetPosition(pos);
    transform->SetRotation(rot);
    transform->SetScale(scl);
}

Entity::Entity(std::string _name, Vector2 pos, float rot, Vector2 scl)
{
    isActive = true;
    layer = 0;
    tag = "Default";
    name = _name;
    transform = AddComponent<Transform>();
    transform->SetPosition(pos);
    transform->SetRotation(rot);
    transform->SetScale(scl);
}

bool Entity::RemoveComponent(BehaviourScript* check)
{
    int i=0;
    for(auto script:this->components)
    {
        if(script == check)
        {
            this->components.erase(this->components.begin()+i);
            return true;
        }
        i++;
    }
    return false;
}

Entity* Entity::Find(std::string _name)
{
    for(int i=0,n=SceneManager::currentScene->entities.size();i<n;i++)
    {
        if(SceneManager::currentScene->entities[i]->name == _name)
        {
            return SceneManager::currentScene->entities[i];
        }
    }
    Debug::LogError("Entity with name \"" + _name +"\" doesn't exist!");
    return nullptr;
}

Entity* Entity::Instantiate(std::string _name)
{
    SceneManager::currentScene->entities.push_back(new Entity(_name));
    return SceneManager::currentScene->entities[SceneManager::currentScene->entities.size()-1];
}

Entity* Entity::Instantiate(Vector2 pos, float rot, Vector2 scl)
{
    SceneManager::currentScene->entities.push_back(new Entity(pos, rot, scl));
    return SceneManager::currentScene->entities[SceneManager::currentScene->entities.size()-1];
}

Entity* Entity::Instantiate(std::string _name, Vector2 pos, float rot, Vector2 scl)
{
    SceneManager::currentScene->entities.push_back(new Entity(_name, pos, rot, scl));
    return SceneManager::currentScene->entities[SceneManager::currentScene->entities.size()-1];
}