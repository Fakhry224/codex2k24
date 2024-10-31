# Use Python 3.10-slim image
FROM python:3.10-slim

# Set the working directory
WORKDIR /app/a/b/c/d/e/f

# Create the necessary directory structure within the container
RUN mkdir -p a/b/c/d/e/f

# Copy the requirements file into the nested structure
COPY a/b/c/d/e/f/requirements.txt /app/a/b/c/d/e/f/requirements.txt

# Copy the application files into the nested structure
COPY a/b/c/d/e/f/app.py /app/a/b/c/d/e/f/app.py
COPY a/b/c/d/e/f/templates /app/a/b/c/d/e/f/templates

# Install dependencies from requirements.txt in the nested structure
RUN pip install --no-cache-dir -r /app/a/b/c/d/e/f/requirements.txt

# Expose the application port
EXPOSE 5002

# Set the default command to run the app
CMD ["python", "/app/a/b/c/d/e/f/app.py"]
