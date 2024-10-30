
float f_derivative(float x)
{
    return (6*pow(x,5) - 1);

}


float f(float x)
{
    return (pow(x,6) - x -1);
}


float absValue(float a)
{
    if (a>=0)
        return a;
    else
        return (-a);
}


float rootBisection(float x0, float x1)
{
    float x2, root;

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        while (1)
        {
            if (fabs(x2 - x1) < 0.0001) 
            {
                root = x2;
                break;
            }

            x0 = x1;
            x1 = x2;
        }
        return root;
    
}

float rootNewton(float x0)
{
    float x1, root;
    while (1) 
    {              
            x1 = x0 - f(x0) / f_derivative(x0);
     
            if (absValue(f(x1)) < 0.001)
            {
                root = x1;
                break;
            }
            // Update x0 for the next iteration
            x0 = x1;
    }
    return root;
}

float rootSecant(float x0, float x1)
{
    float x2, root;
    while (1)
    {
        // Calculate the next approximation
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        // Check for convergence
        if (fabs(x2 - x1) < 0.0001) 
        {
            root = x2;
            break;
        }

        // Update for next iteration
        x0 = x1;
        x1 = x2;
    }
    return root;
}
