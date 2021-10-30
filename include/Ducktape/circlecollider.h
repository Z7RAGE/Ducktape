#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

class CircleCollider : public BehaviourScript
{
public:
    Rigidbody* rb;

    float density = 1.0f;
    float friction = 0.3f;
    bool isTrigger = false;
    float radius = 1.0f;
    
    void Start()
    {
        rb = gameObject->GetComponent<Rigidbody>();

        b2CircleShape circleShape;

        circleShape.m_p.Set(0.0f, 0.0f);
        circleShape.m_radius = radius;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &circleShape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.isSensor = isTrigger;
        
        rb->body->CreateFixture(&fixtureDef);
    }
};

#endif