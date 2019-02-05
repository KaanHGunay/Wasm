#include <emscripten.h>
#include <math.h>

EMSCRIPTEN_KEEPALIVE
int fib(int n) {
    int i, t, a = 0, b = 1;
    for(i = 0; i < n; i++)
    {
        t = a + b;
        a = b;
        b = t;
    }
    return b;    
}

EMSCRIPTEN_KEEPALIVE
int add(int x, int y) {
    return x + y;
}

EM_JS(void, drawCircle, (float x, float y, float r), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.fillStyle = '#ff0000';
    context.beginPath();
    context.arc(x, y, r, 0, Math.PI);
    context.fill();
});

EM_JS(void, test, (), {
    const h1 = document.querySelector('h1');
    h1.innerHTML = "Çalıştı";
});

EM_JS(void, addDeleteButton, (), {
    const deleteButton = document.createElement("button");
    deleteButton.appendChild(document.createTextNode("Sil"));
    const div = document.querySelector('div');
    div.appendChild(deleteButton);
});

ELJS(void, clearCanvas, (), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.clearRect(0, 0, canvas.width, canvas.height);
});

static float t = 0.0;
extern "C" { 
    EMSCRIPTEN_KEEPALIVE
    void update() {
        float dt = 1.0f / 60.0f;
        t += dt;
        clearCanvas();
        drawCircle(350 + (sin(t) * 200), 275 - (sin(t * 2) * 200), 50.0);
    }
}

int main(int argc, char const *argv[])
{
    drawCircle();
    return 0;
}
 