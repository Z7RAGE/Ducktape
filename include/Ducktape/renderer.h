#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
    public:
        static void DrawSprite(std::string path, Vector2 pos, float rot, Vector2 scl, int pixelPerUnit)
        {
            sf::Texture texture;
            if (!texture.loadFromFile(path))
            {
                Debug::LogError("Error loading sprite from " + path);
                return;
            }

            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(pos.ToSFMLVector());
            sprite.setRotation(rot);
            sprite.setScale((scl/pixelPerUnit).ToSFMLVector());
            sprite.setOrigin(sf::Vector2f(texture.getSize().x/2, texture.getSize().y/2));

            Application::renderWindow.draw(sprite);
        }
};

#endif