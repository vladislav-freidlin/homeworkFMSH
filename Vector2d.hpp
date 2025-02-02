#pragma once

struct Vector2d{

    float x;
    float y;
    const float defaultLenght = 1.0;
    float lenght;

    Vector2d();
    Vector2d(float x, float y){
        this->x = x;
        this->y = y;
    }   
    Vector2d(float x, float y, float len){
        this->x = x;
        this->y = y;
        this->lenght = len;
    }
    
    Vector2d operator=(const Vector2d &vec);
    Vector2d operator-();

    float getLenght(){
        if(this->lenght){
            return lenght;
        }
        return defaultLenght;
    }
};

Vector2d Vector2d::operator=(const Vector2d &vec){
    return Vector2d{vec.x, vec.y};
}
Vector2d Vector2d::operator-(){
    return Vector2d{-this->x, -this->y};
}
Vector2d operator*(const float &num, const Vector2d &vec){
    return Vector2d{vec.x * num, vec.y * num};
}
Vector2d operator*(const Vector2d &vec, const float &num){
    return Vector2d{vec.x * num, vec.y * num};
}
Vector2d operator+=(const Vector2d &vec1, const Vector2d &vec2){
    return Vector2d{vec1.x + vec2.x, vec1.y + vec2.y};
}
Vector2d operator/(const Vector2d &vec, const float &num){
    return Vector2d{vec.x / num, vec.y / num};
}
Vector2d operator-(const Vector2d &vec1, const Vector2d &vec2){
    return Vector2d{vec1.x - vec2.x, vec1.y - vec2.y};
}
Vector2d operator+(const Vector2d &vec1, const Vector2d &vec2){
    return Vector2d{vec1.x + vec2.x, vec1.y + vec2.y};
}